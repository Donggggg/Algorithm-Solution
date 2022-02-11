const MAX = 4000;
let range = [...Array.from(Array(MAX + 2))];

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  solution(input[0], input[1]);
})();

function getLongestCommonString(str1, str2) {
  let answer = 0;
  let table = range.map((_) => range.map((_) => 0));

  for (let i = 1; i <= str1.length; i++)
    for (let j = 1; j <= str2.length; j++)
      if (str1[i - 1] == str2[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
        answer = Math.max(answer, table[i][j]);
      }

  return answer;
}

function solution(str1, str2) {
  console.log(getLongestCommonString(str1, str2));
}
