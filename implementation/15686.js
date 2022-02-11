const MAX = 100;
const DIRS = 4;
const dx = [1, 0, -1, 0];
const dy = [0, -1, 0, 1];
const range = [...Array.from(Array(MAX + 1))];

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  let N = input[0];
  let curves = [];
  
  for (let i = 1; i < input.length; i++)
    curves.push(input[i].split(" ").map((e) => Number(e)));

  solution(N, curves);
})();

function move(curX, curY, dir, hist) {
  curX += dx[dir];
  curY += dy[dir];
  hist.push(dir);
  return { x: curX, y: curY };
}

function setCurve(curve, map) {
  const turnLeft = (dir) => (dir + 1) % DIRS;
  const tranposeDirection = (dir) => (((dir + 3) % DIRS) + 2) % DIRS;
  let [curX, curY, curD, gene] = curve;
  let hist = [];

  map[curY][curX] = true;
  curX += dx[curD];
  curY += dy[curD];
  hist.push(curD);
  curD = turnLeft(curD);

  while (0 < gene--) {
    for (let i = hist.length - 1; 0 <= i; i--) {
      let res = move(curX, curY, tranposeDirection(hist[i]), hist);
      map[curY][curX] = true;
      curX = res.x;
      curY = res.y;
    }
  }

  map[curY][curX] = true;
}

function getSquareNumber(map) {
  let nx = [1, 1, 0];
  let ny = [0, 1, 1];
  let num = 0;

  for (let i = 0; i < MAX; i++)
    for (let j = 0; j < MAX; j++)
      if (
        map[i][j] > 0 &&
        map[i + ny[0]][j + nx[0]] > 0 &&
        map[i + ny[1]][j + nx[1]] > 0 &&
        map[i + ny[2]][j + nx[2]] > 0
      )
        num++;

  return num;
}

function solution(N, curves) {
  let map = range.map((_) => range.map((_) => false));
  for (let i = 0; i < N; i++) setCurve(curves[i], map);
  console.log(getSquareNumber(map));
}
