function solution() {
  // solve the problem
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  // process the input
  solution();
})();
