function reverse(S) {
  let str = "";
  for (let i = S.length - 1; 0 <= i; i--) str = str + S[i];
  return str;
}

function check(S, T) {
  if (S == T) return 1;
  if (T.length <= S.length) return 0;

  if (T[T.length - 1] == "A") {
    if (check(S, T.slice(0, T.length - 1))) return 1;
  } else {
    if (check(S, reverse(T.slice(0, T.length - 1)))) return 1;
  }

  return 0;
}

function solution(S, T) {
  console.log(Number(check(S, T)));
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  solution(input[0], input[1]);
})();
