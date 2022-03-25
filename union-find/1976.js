function getParent(v, parent) {
  if (v == parent[v]) return v;
  else return (parent[v] = getParent(parent[v], parent));
}

function union(v1, v2, parent) {
  const pv1 = getParent(v1, parent);
  const pv2 = getParent(v2, parent);

  if (pv1 > pv2) parent[pv1] = pv2;
  else if(pv1 < pv2) parent[pv2] = pv1;
}

function solution(N, M, graph, plan) {
  const parent = [...Array.from(Array(N + 1))].map((_, idx) => idx);

  for (let i = 0; i < N; i++)
    for (let j = 0; j < N; j++) if (graph[i][j]) union(i + 1, j + 1, parent);

  const p = getParent(plan[0], parent);

  for (let i = 1; i < M; i++)
    if (p != getParent(plan[i], parent)) {
      console.log("NO");
      return;
    }

  console.log("YES");
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  const graph = [];
  for (let i = 2; i < input.length - 1; i++)
    graph.push(input[i].split(" ").map(Number));
  const plan = input[input.length - 1].split(" ").map(Number);
  solution(Number(input[0]), Number(input[1]), graph, plan);
})();
