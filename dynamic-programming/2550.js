Array.prototype.lowerBound = function (target) {
  let left = 0;
  let right = this.length - 1;
  let idx = this.length;

  while (left <= right) {
    let mid = Math.floor((right + left) / 2);

    if (target <= this[mid]) {
      right = mid - 1;
      idx = Math.min(mid, idx);
    } else if (target > this[mid]) left = mid + 1;
  }

  return idx;
};

function print(size, index, bulbs) {
  let current = size - 1;
  let answer = [];

  console.log(size);

  for (let i = index.length - 1; 0 <= i; i--)
    if (current == index[i]) {
      answer.push(bulbs[i]);
      current--;
    }

  console.log(
    answer.sort((a, b) => a - b).reduce((acc, cur) => `${acc}${cur} `, "")
  );
}

function solution(N, switchs, bulbs) {
  let arr = [];
  let list = [];
  let matchs = [...Array.from(Array(N + 1))].map((_) => 0);
  let index = [...Array.from(Array(N))].map((_) => 0);

  for (let i = 0; i < N; i++) matchs[switchs[i]] = i + 1;
  for (let i = 0; i < N; i++) arr.push(matchs[bulbs[i]]);

  for (let i = 0; i < N; i++) {
    let idx = list.lowerBound(arr[i]);
    if (idx == list.length) list.push(arr[i]);
    else list[idx] = arr[i];
    index[i] = idx;
  }

  print(list.length, index, bulbs);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  solution(
    Number(input[0]),
    input[1].split(" ").map((e) => Number(e)),
    input[2].split(" ").map((e) => Number(e))
  );
})();
