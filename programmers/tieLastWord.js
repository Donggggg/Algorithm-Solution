function solution(n, words) {
  let answer = [0, 0];
  let wordSet = new Set();

  for (let idx = 0; idx < words.length; idx++) {
    const word = words[idx];
    if (
      !(idx === 0) &&
      (wordSet.has(word) || words[idx - 1].slice(-1) !== word[0])
    ) {
      answer = [(idx % n) + 1, Math.floor(idx / n) + 1];
      break;
    } else wordSet.add(word);
  }

  return answer;
}
