function solution(s) {
  const center = Math.floor(s.length / 2);
  if (s.length % 2) return s[center];
  else return s[center - 1] + s[center];
}
