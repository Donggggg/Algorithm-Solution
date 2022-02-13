function gerenateStar(n, x, y, stars) {
  if (3 < n) {
    gerenateStar(n / 2, x + n / 2, y, stars);
    gerenateStar(n / 2, x, y + n / 2, stars);
    gerenateStar(n / 2, x + n / 2 + n / 3 + n / 6, y + n / 2, stars);
  } else {
    const starString = ["  *  ", " * * ", "*****"];

    for (let i = 0; i < 3; i++)
      for (let s = 0; s < 5; s++)
        stars[y + i][s + x] = starString[i][s] === "*";
  }
}

function solution(N) {
  const total = (5 * N) / 3 + N / 3 - 1;
  const range = [...Array.from(Array(total))];
  let stars = range.map((_) => range.map((_) => false));

  gerenateStar(N, 0, 0, stars);

  for (let i = 0; i < N; i++)
    console.log(stars[i].reduce((acc, cur) => `${acc}${cur ? "*" : " "}`, ""));
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  solution(Number(input[0]));
})();
