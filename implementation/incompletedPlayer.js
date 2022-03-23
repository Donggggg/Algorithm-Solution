function solution(participant, completion) {
  const map = new Map();

  participant.forEach((name) => {
    if (map.has(name)) map.set(name, map.get(name) + 1);
    else map.set(name, 1);
  });

  completion.forEach((name) => {
    if (map.has(name)) map.set(name, map.get(name) - 1);
  });

  for (const item of map) if (item[1] > 0) return item[0];
}
