function checkSame(i, L, road) {
  for (let idx = i; idx < i + L - 1; idx++)
    if (road[idx] != road[idx + 1]) return false;
  if (road[i - 1] == road[i + L]) return false;
  return (
    (0 <= i - 1 && road[i] == road[i - 1] - 1) ||
    (i + L < road.length && road[i] == road[i + L] - 1)
  );
}

function getRunway(L, road) {
  let runway = [...Array.from(Array(road.length))].map((_) => 0);

  for (let i = 0; i <= road.length - L; i++) {
    if (checkSame(i, L, road)) {
      for (let j = 0; j < L; j++) runway[i + j] += 1;
      i += L - 1;
    }
  }

  return runway;
}

function checkLine(L, road) {
  const runway = getRunway(L, road);

  for (let i = 0; i < road.length - 1; i++) {
    if (road[i] == road[i + 1]) continue;
    if (Math.abs(road[i] - road[i + 1]) != 1) return false;
    if (road[i] > road[i + 1] && !runway[i + 1]) return false;
    if (road[i] < road[i + 1] && !runway[i]) return false;
  }

  return true;
}

function solution(N, L, roadMap) {
  let count = 0;
  let columnMap = [...Array.from(Array(N))].map((_) => []);
  for (let i = 0; i < N; i++) {
    if (checkLine(L, roadMap[i])) count++;
    for (let j = 0; j < N; j++) columnMap[j].push(roadMap[i][j]);
  }

  for (let i = 0; i < N; i++) if (checkLine(L, columnMap[i])) count++;

  console.log(count);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  let [N, L] = input[0].split(" ").map((e) => Number(e));
  let road = [];
  for (let i = 1; i < input.length; i++)
    road.push(input[i].split(" ").map((e) => Number(e)));
  solution(N, L, road);
})();
