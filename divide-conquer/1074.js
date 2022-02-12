let current = 0;
let R;
let C;

function getZMapOrder(size, r, c) {
  let inc = 2 < size ? Math.floor(size / 2) ** 2 : 1;
  let nr = r + size / 2;
  let nc = c + size / 2;
  
  const checkRange = (x, nx, y, ny) => {
    if (x <= R && R < nx && y <= C && C < ny) return true;
    else current += inc;
    return false;
  };
  
  if (r == R && c == C) {
    console.log(current);
    return;
  }
  
  if (checkRange(r, nr, c, nc)) getZMapOrder(size / 2, r, c);
  if (checkRange(r, nr, nc, c + size)) getZMapOrder(size / 2, r, nc);
  if (checkRange(nr, r + size, c, nc)) getZMapOrder(size / 2, nr, c);
  if (checkRange(nr, r + size, nc, c + size)) getZMapOrder(size / 2, nr, nc);
}

function solution(N, r, c) {
  R = r;
  C = c;
  getZMapOrder(2 ** N, 0, 0);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  let line = input[0].split(" ");
  solution(line[0], line[1], line[2]);
})();