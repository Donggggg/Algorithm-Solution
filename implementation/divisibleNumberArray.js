function solution(arr, divisor) {
  const answers = arr.filter((e) => e % divisor === 0).sort((a, b) => a - b);
  return answers.length === 0 ? [-1] : answers;
}
