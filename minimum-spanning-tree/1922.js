function getParent(parent, v) {
    if(parent[v] == v) return v;
    else return parent[v] = getParent(parent, parent[v]);
}

function unionParent(parent, v1, v2) {
    let nv1 = getParent(parent, v1);
    let nv2 = getParent(parent, v2);

    if(nv1 > nv2) parent[nv1] = nv2;
    else parent[nv2] = nv1;
}

function hasEqualParent(parent, v1, v2) {
    return getParent(parent, v1) == getParent(parent, v2);
}

function getMinimumPrice(N, edges) {
  let parent = [...Array.from(Array(N+1))].map((_, idx) => idx);
  let price = 0;
  let current = 0;

  for(let i = 0; i < edges.length; i++) {
      if(current == N - 1) break;
      const {v1, v2, w} = edges[i];

      if(hasEqualParent(parent, v1, v2)) continue;

      price += w;
      current++;
      unionParent(parent, v1, v2);
  }

  return price;
}

function solution(N, M, edges) {
    edges.sort((a, b) => a.w - b.w);
    console.log(getMinimumPrice(N, edges));
  }
  
  (function () {
    let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
    input = input
      .slice(0, input.length - 1)
      .map((line) => line.replace("\r", ""));

    let edges = [];
    for(let i = 2; i < input.length; i++) {
        const [v1, v2, w] = input[i].split(' ').map(Number);
        edges.push({v1, v2, w});
    }
    
    solution(Number(input[0]), Number(input[1]), edges);
  })();
  