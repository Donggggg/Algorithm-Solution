function combination(n, r) {
  let up = 1;
  let down = 1;

  for (let i = 0; i < r; i++) {
    up *= n - i;
    down *= i + 1;
  }

  return up / down;
}

function solution(clothes) {
  const map = new Map();
  let answer = 1;

  clothes.forEach((item) => {
    if (map.has(item[1])) map.set(item[1], map.get(item[1]) + 1);
    else map.set(item[1], 1);
  });

  for (const [_, n] of map) {
    answer *= combination(n, 1) + 1;
  }

  return answer - 1;
}
