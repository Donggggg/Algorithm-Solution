const INF = 1e7;

function solution(N, M, arr) {
  let dist = arr.map((line) => [...line]);

  for (let k = 1; k <= N; k++)
    for (let i = 1; i <= N; i++)
      for (let j = 1; j <= N; j++)
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];

  dist
    .slice(1)
    .forEach((line) =>
      console.log(
        line.slice(1).reduce((acc, cur) => `${acc}${cur == INF ? 0 : cur} `, "")
      )
    );
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  const N = Number(input[0]);
  const range = [...Array.from(Array(N + 1))];
  let arr = range.map((_) => range.map((_) => INF));

  for (let i = 2; i < input.length; i++) {
    const [x, y, w] = input[i].split(" ").map(Number);
    if (arr[x][y] > w) arr[x][y] = w;
  }

  for (let i = 1; i <= N; i++) arr[i][i] = 0;

  solution(Number(input[0]), Number(input[1]), arr);
})();
