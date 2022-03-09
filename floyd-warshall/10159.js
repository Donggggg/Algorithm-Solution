const ASC = 1;
const DESC = -1;
const DRAW = 0;
const UNKNOWN = -2;

function printResult(N, table) {
  for (let i = 1; i <= N; i++) {
    console.log(
      table[i].slice(1).reduce((acc, cur) => acc + (cur == UNKNOWN ? 1 : 0), 0)
    );
  }
}

function solution(N, arr) {
  let table = arr.map((line) => [...line]);

  for (let k = 1; k <= N; k++)
    for (let i = 1; i <= N; i++)
      for (let j = 1; j <= N; j++) {
        if (table[i][j] == UNKNOWN && table[i][k] == ASC && table[k][j] == ASC)
          table[i][j] = ASC;
        if (table[i][j] == UNKNOWN && table[i][k] == DESC && table[k][j] == DESC)
          table[i][j] = DESC;
      }

  printResult(N, table);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  const N = Number(input[0]);
  const range = [...Array.from(Array(N + 1))];
  let arr = range.map((_) => range.map((_) => UNKNOWN));

  for (let i = 2; i < input.length; i++) {
    const [x, y] = input[i].split(" ").map(Number);
    arr[x][y] = ASC;
    arr[y][x] = DESC;
  }

  for (let i = 1; i <= N; i++) arr[i][i] = DRAW;

  solution(N, arr);
})();
