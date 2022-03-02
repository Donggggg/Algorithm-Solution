function getParent(parent, v) {
  if (v == parent[v]) return v;
  else return (parent[v] = getParent(parent, parent[v]));
}

function unionParent(parent, v1, v2) {
  let nv1 = getParent(parent, v1);
  let nv2 = getParent(parent, v2);

  if (nv1 > nv2) parent[nv1] = nv2;
  else parent[nv2] = nv1;
}

function hasEqualParent(parent, v1, v2) {
  return getParent(parent, v1) == getParent(parent, v2);
}

function getMinimumWeight(edgeNum, edges) {
  let parent = [...Array.from(Array(edgeNum + 2))].map((_, idx) => idx);
  let currentEdgeNum = 0;
  let weight = 0;

  for (let i = 0; i < edges.length; i++) {
    let { v1, v2, w } = edges[i];

    if (edgeNum == currentEdgeNum) break;

    if (!hasEqualParent(parent, v1, v2)) {
      weight += w;
      currentEdgeNum++;
      unionParent(parent, v1, v2);
    }
  }

  return weight;
}

function solution(V, E, edges) {
  edges.sort((a, b) => a.w - b.w);
  console.log(getMinimumWeight(V - 1, edges));
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  const [V, E] = input[0].split(" ").map(Number);
  let edges = [];
  for (let i = 1; i < input.length; i++) {
    const [v1, v2, w] = input[i].split(" ").map(Number);
    edges.push({ v1, v2, w });
  }

  solution(V, E, edges);
})();
