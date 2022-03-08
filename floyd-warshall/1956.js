const INF = 4e6 + 1;

function getDistanceTable(N, arr) {
  let distance = arr.map((line) => [...line]);

  for (let k = 1; k <= N; k++)
    for (let i = 1; i <= N; i++)
      for (let j = 1; j <= N; j++)
        if (distance[i][k] + distance[k][j] < distance[i][j])
          distance[i][j] = distance[i][k] + distance[k][j];

  return distance;
}

function getPathCost(N, distacne) {
  let cost = INF;

  for (let i = 1; i <= N; i++)
    for (let j = 1; j <= N; j++)
      if (i != j && distacne[i][j] + distacne[j][i] < cost)
        cost = distacne[i][j] + distacne[j][i];

  return INF <= cost ? -1 : cost;
}

function solution(N, M, arr) {
  const distance = getDistanceTable(N, arr);
  console.log(getPathCost(N, distance));
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  const [N, M] = input[0].split(" ").map(Number);
  let range = [...Array.from(Array(N + 1))];
  let arr = range.map((_) => range.map((_) => INF));

  for (let i = 1; i < input.length; i++) {
    const [x, y, w] = input[i].split(" ").map(Number);
    arr[x][y] = w;
  }
  for (let i = 1; i <= N; i++) arr[i][i] = 0;
  solution(N, M, arr);
})();
