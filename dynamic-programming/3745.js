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

function getLongestStream(stream) {
  let arr = [];

  for (let i = 0; i < stream.length; i++) {
    let index = arr.lowerBound(stream[i]);
    if (index == arr.length) arr.push(stream[i]);
    else arr[index] = stream[i];
  }

  return arr.length;
}

function solution(days, streams) {
  for (let i = 0; i < days.length; i++)
    console.log(getLongestStream(streams[i]));
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  let days = [];
  let streams = [];
  for (let i = 0; i < input.length; i += 2) {
    days.push(Number(input[i]));
    streams.push(input[i + 1].trim().split(/\s+/g).map(Number));
  }
  solution(days, streams);
})();
