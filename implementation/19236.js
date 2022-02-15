let sum = 0;
let dr = [-1, -1, 0, 1, 1, 1, 0, -1];
let dc = [0, -1, -1, -1, 0, 1, 1, 1];

function checkMovable(r, c, shark) {
  return !(
    r < 0 ||
    c < 0 ||
    4 <= r ||
    4 <= c ||
    (r == shark.r && c == shark.c)
  );
}

function copySpace(space) {
  let nextSpace = [];
  for (let i = 0; i < space.length; i++) {
    let next = [];

    for (let j = 0; j < space[i].length; j++) next.push({ ...space[i][j] });

    nextSpace.push(next);
  }

  return nextSpace;
}

function changeFish(r, c, shark, space) {
  let { d } = space[r][c];

  for (let vd = 0; vd < 8; vd++) {
    let nd = (d + vd) % 8;
    let nr = r + dr[nd];
    let nc = c + dc[nd];

    if (checkMovable(nr, nc, shark)) {
      space[r][c].d = nd;
      let tempFish = { ...space[nr][nc] };
      space[nr][nc] = space[r][c];
      space[r][c] = tempFish;
      break;
    }
  }
}

function moveFish(cur, shark, space) {
  for (let i = 0; i < 4; i++)
    for (let j = 0; j < 4; j++)
      if (space[i][j].size == cur && space[i][j].alive) {
        changeFish(i, j, shark, space);
        return;
      }
}

function getNextSharkPos(shark, space) {
  let pos = [];
  let { r, c, d } = shark;

  while (0 <= r && 0 <= c && r < 4 && c < 4) {
    let nr = r + dr[d];
    let nc = c + dc[d];

    if (checkMovable(nr, nc, shark) && space[nr][nc].alive)
      pos.push({ r: nr, c: nc });

    r = nr;
    c = nc;
  }

  return pos;
}

function simulate(shark, total, space) {
  sum = Math.max(total, sum);

  for (let cur = 1; cur <= 16; cur++) moveFish(cur, shark, space);

  let targets = getNextSharkPos(shark, space);

  if (0 < targets.length) {
    targets.forEach((next) => {
      let { r, c } = next;
      let nextSpace = copySpace(space);
      let nextShark = { r, c, d: space[r][c].alive ? space[r][c].d : shark.d };
      let nextSize = total + (space[r][c].alive ? space[r][c].size : 0);

      nextSpace[r][c].alive = false;
      
      simulate(nextShark, nextSize, nextSpace);
    });
  }
}

function solution(space) {
  space[0][0].alive = false;
  simulate({ r: 0, c: 0, d: space[0][0].d }, space[0][0].size, space);
  console.log(sum);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  let space = [];
  for (let i = 0; i < input.length; i++) {
    let line = input[i].split(" ").map((e) => Number(e));
    let next = [];

    for (let i = 0; i < line.length; i += 2)
      next.push({ size: line[i], d: line[i + 1] - 1, alive: true });

    space.push(next);
  }

  solution(space);
})();
