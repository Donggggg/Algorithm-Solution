let answer = "";

function checkCompressible(mark, size, r, c, image) {
  for (let i = r; i < r + size; i++)
    for (let j = c; j < c + size; j++) 
      if (mark != image[i][j]) return false;
  return true;
}

function compress(size, r, c, image) {
    let mark = image[r][c];
    
    if (checkCompressible(mark, size, r, c, image)) {
      answer += String(mark);
  }
  else {
      answer += '(';
      compress(size / 2, r, c, image);
      compress(size / 2, r, c + size / 2, image);
      compress(size / 2, r + size / 2, c, image);
      compress(size / 2, r + size / 2, c + size / 2, image);
      answer += ')';
  }
}

function solution(N, image) {
  compress(N, 0, 0, image);
  console.log(answer);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  let image = [];

  for (let i = 1; i < input.length; i++)
    image.push(input[i].split("").map((e) => Number(e)));

  solution(input[0], image);
})();