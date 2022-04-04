function solution(N, M, arr) {
  let width = 0;
  let visit = [...Array.from(Array(N))].map((_) =>
    [...Array.from(Array(M))].map((_) => 0)
  );

  for (let i = 0; i < N; i++)
    if (arr[i][0]) {
      visit[i][0] = 1;
      width = 1;
    }
  for (let i = 0; i < M; i++)
    if (arr[0][i]) {
      visit[0][i] = 1;
      width = 1;
    }

  for (let i = 1; i < N; i++)
    for (let j = 1; j < M; j++)
      if (arr[i][j] == 1) {
        visit[i][j] =
          Math.min(visit[i - 1][j], visit[i][j - 1], visit[i - 1][j - 1]) + 1;
        width = Math.max(width, visit[i][j]);
      }

  console.log(width * width);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  const [N, M] = input[0].split(" ").map(Number);
  const arr = [];
  for (let i = 1; i < input.length; i++)
    arr.push(input[i].split("").map(Number));
  solution(N, M, arr);
})();
