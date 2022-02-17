function solution(str1, str2) {
  const range = [...Array.from(Array(1001))];
  let table = range.map((_) => range.map((_) => 0));

  for (let i = 1; i <= str1.length; i++)
    for (let j = 1; j <= str2.length; j++)
      table[i][j] =
        str1[i - 1] === str2[j - 1]
          ? table[i - 1][j - 1] + 1
          : Math.max(table[i - 1][j], table[i][j - 1]);

  console.log(table[str1.length][str2.length]);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  solution(input[0], input[1]);
})();
