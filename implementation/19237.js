let liveCount;

function generateGrid(grid) {
  return [...Array.from(Array(grid.length))].map((_) =>
    [...Array.from(Array(grid.length))].map((_) => false)
  );
}

function getNextPos(shark, grid) {
  let dr = [-1, 1, 0, 0];
  let dc = [0, 0, -1, 1];
  let { r, c, d } = shark;
  let ownTarget;

  for (let i = 0; i < 4; i++) {
    let nd = shark.prio[d][i];
    let nr = r + dr[nd];
    let nc = c + dc[nd];

    if (nr < 0 || nc < 0 || grid.length <= nr || grid.length <= nc) continue;
    if (grid[nr][nc].smell == 0) return { r: nr, c: nc, d: nd };
    if (grid[nr][nc].own == shark.id && ownTarget == undefined) ownTarget = { r: nr, c: nc, d: nd };
  }

  return ownTarget;
}

function moveShark(grid, sharks) {
  let table = generateGrid(grid);

  for (let key in sharks) {
    let res = getNextPos(sharks[key], grid);
    let { r, c, d } = res;

    if (table[r][c]) {
      liveCount--;
      delete sharks[key];
      continue;
    }

    table[r][c] = true;
    sharks[key] = { ...sharks[key], r, c, d };
  }
}

function decreaseSmell(grid) {
  for (let i = 0; i < grid.length; i++)
    for (let j = 0; j < grid.length; j++)
      if (0 < grid[i][j].smell) {
        if (--grid[i][j].smell == 0) grid[i][j].own = 0;
      }
}

function spreadSmell(k, grid, sharks) {
  for (let key in sharks) {
    let { r, c } = sharks[key];
    grid[r][c] = { smell: k, own: Number(key) };
  }
}

function solution(M, k, grid, sharks) {
  liveCount = M;
  let tick = 0;

  while (tick <= 1000) {
    if (liveCount == 1) break;
    moveShark(grid, sharks);
    decreaseSmell(grid);
    spreadSmell(k, grid, sharks);
    tick++;
  }

  console.log(tick > 1000 ? -1 : tick);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  let [N, M, k] = input[0].split(" ").map((e) => Number(e));
  let grid = [];
  let sharks = {};
  for (let i = 1; i <= N; i++)
    grid.push(
      input[i].split(" ").map((e, idx) => {
        if (e > 0) {
          sharks[e] = { id: Number(e), r: i - 1, c: idx };
          return { smell: k, own: Number(e) };
        }
        return { smell: 0, own: 0 };
      })
    );

  input[N + 1].split(" ").map((e, idx) => (sharks[idx + 1].d = Number(e) - 1));

  for (let i = N + 2; i < input.length; i += 4) {
    let prio = [];
    for (let j = 0; j < 4; j++)
      prio.push(input[i + j].split(" ").map((e) => Number(e) - 1));
    sharks[(i - N + 2) / 4].prio = prio;
  }

  solution(M, k, grid, sharks);
})();
