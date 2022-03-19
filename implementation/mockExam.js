function getWinners(answers) {
  const randoms = [
    [1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
  ];
  let winers = [];
  const corrects = [0, 0, 0];

  for (let i = 0; i < answers.length; i++) {
    const answer = answers[i];
    if (randoms[0][i % randoms[0].length] == answer) corrects[0]++;
    if (randoms[1][i % randoms[1].length] == answer) corrects[1]++;
    if (randoms[2][i % randoms[2].length] == answer) corrects[2]++;
  }

  const max = Math.max(...corrects);
  for (let i = 0; i < corrects.length; i++) {
    if (max == corrects[i]) winers.push(i + 1);
  }

  return winers;
}

function solution(answers) {
  return getWinners(answers);
}
