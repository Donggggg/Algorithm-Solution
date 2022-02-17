function printAnswer(num, str1, str2, table) {
  console.log(num);

  if (0 == num) return;

  let answer = "";

  for (let i = str2.length; 0 < i; i--) {
    for (let j = 1; j <= str1.length; j++) {
      if (
        table[i][j] != table[i - 1][j] &&
        table[i][j] != table[i][j - 1] &&
        table[i][j] == num
      ) {
        answer = `${str1[j - 1]}${answer}`;
        num--;
      }
    }
  }
  console.log(answer);
}

function solution(str1, str2) {
  const range = [...Array.from(Array(1001))];
  let table = range.map((_) => range.map((_) => 0));

  for (let i = 1; i <= str2.length; i++)
    for (let j = 1; j <= str1.length; j++)
      table[i][j] =
        str1[j - 1] === str2[i - 1]
          ? table[i - 1][j - 1] + 1
          : Math.max(table[i - 1][j], table[i][j - 1]);

  printAnswer(table[str2.length][str1.length], str1, str2, table);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  solution(input[0], input[1]);
})();
