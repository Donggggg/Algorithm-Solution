const MAX = 20000;
let answer;

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  const N = input[0];
  let table = [];

  for (let i = 1; i < input.length; i++)
    table.push(input[i].split(" ").map((e) => Number(e)));

  solution(N, table);
})();

function getPowerDiff(start, link, table) {
  let startPower = 0;
  let linkPower = 0;

  for (let i = 0; i < start.length; i++) {
    for (let j = i + 1; j < start.length; j++) {
      let p1 = start[i];
      let p2 = start[j];
      startPower += table[p1][p2] + table[p2][p1];
    }
  }

  for (let i = 0; i < link.length; i++) {
    for (let j = i + 1; j < link.length; j++) {
      let p1 = link[i];
      let p2 = link[j];
      linkPower += table[p1][p2] + table[p2][p1];
    }
  }

  return Math.abs(startPower - linkPower);
}

function getBalancedTeam(depth, start, link, N, table) {
  if (depth == N) {
    answer = Math.min(getPowerDiff(start, link, table), answer);
    return;
  }

  if (start.length < N / 2) {
    nextStart = [...start];
    nextStart.push(depth);
    getBalancedTeam(depth + 1, nextStart, link, N, table);
  }

  if (link.length < N / 2) {
    nextLink = [...link];
    nextLink.push(depth);
    getBalancedTeam(depth + 1, start, nextLink, N, table);
  }
}

function solution(N, table) {
  
  answer = MAX;
  getBalancedTeam(0, [], [], N, table);

  console.log(answer);
}
