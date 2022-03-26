const HEIGHT = 12;
const WIDTH = 6;

function eliminate(r, c, visit, map) {
  const dr = [0, 1, -1, 0];
  const dc = [1, 0, 0, -1];
  const queue = [];
  const color = map[r][c];
  const newVisit = visit.map((l) => [...l]);
  let cnt = 0;

  newVisit[r][c] = true;
  queue.push({ r, c });

  while (queue.length != 0) {
    const { r, c } = queue.shift();
    cnt++;

    for (let d = 0; d < 4; d++) {
      const nr = r + dr[d];
      const nc = c + dc[d];

      if (nr < 0 || nc < 0 || HEIGHT <= nr || WIDTH <= nc) continue;
      if (map[nr][nc] != color || newVisit[nr][nc]) continue;

      newVisit[nr][nc] = true;
      queue.push({ r: nr, c: nc });
    }
  }

  if (4 <= cnt) {
    for (let i = 0; i < HEIGHT; i++)
      for (let j = 0; j < WIDTH; j++) visit[i][j] = newVisit[i][j];
  }
}

function sync(visit, map) {
  let isSynced = false;

  for (let i = 0; i < HEIGHT; i++)
    for (let j = 0; j < WIDTH; j++)
      if (visit[i][j]) {
        map[i][j] = ".";
        isSynced = true;
      }

  return isSynced;
}

function explode(map) {
  const visit = [...Array.from(Array(HEIGHT))].map((_) =>
    [...Array.from(Array(WIDTH))].map((_) => false)
  );

  for (let i = 0; i < HEIGHT; i++)
    for (let j = 0; j < WIDTH; j++)
      if (!visit[i][j] && map[i][j] != ".") eliminate(i, j, visit, map);

  return sync(visit, map);
}

function arange(map) {
  for (let i = 0; i < WIDTH; i++) {
    const buffer = [...Array.from(Array(HEIGHT))].map((_) => ".");
    let bufferIndex = 0;

    for (let j = HEIGHT - 1; 0 <= j; j--)
      if (map[j][i] != ".") buffer[bufferIndex++] = map[j][i];

    for (let j = HEIGHT - 1; 0 <= j; j--) map[j][i] = buffer[HEIGHT - (j + 1)];
  }
}

function solution(map) {
  let combo = 0;

  while (1) {
    if (!explode(map)) break;
    arange(map);
    combo++;
  }

  console.log(combo);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));
  const map = [];
  for (let i = 0; i < input.length; i++) map.push(input[i].split(""));
  solution(map);
})();
