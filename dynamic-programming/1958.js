function solution(str1, str2, str3) {
  const range = [...Array.from(Array(101))];
  let table = range.map((_) => range.map((_) => range.map((_) => 0)));

  for (let i = 1; i <= str1.length; i++)
    for (let j = 1; j <= str2.length; j++)
      for (let k = 1; k <= str3.length; k++)
        table[i][j][k] =
          str1[i - 1] === str2[j - 1] && str2[j - 1] === str3[k - 1]
            ? table[i - 1][j - 1][k - 1] + 1
            : Math.max(
                table[i - 1][j][k],
                table[i][j - 1][k],
                table[i][j][k - 1]
              );

  console.log(table[str1.length][str2.length][str3.length]);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  solution(input[0], input[1], input[2]);
})();
