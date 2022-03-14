function fillRoom(i, j, roomNumber, rooms, castle) {
  let dr = [0, -1, 0, 1];
  let dc = [-1, 0, 1, 0];
  let queue = [];
  let roomWidth = 1;

  rooms[i][j] = roomNumber;
  queue.push({ r: i, c: j });

  while (queue.length != 0) {
    const { r, c } = queue.shift();

    for (let bin = 0; bin < 4; bin++) {
      const nr = r + dr[bin];
      const nc = c + dc[bin];

      if (
        nr < 0 ||
        nc < 0 ||
        rooms.length <= nr ||
        rooms[r].length <= nr ||
        rooms[nr][nc] != -1
      )
        continue;

      if ((castle[r][c] >> bin) % 2 == 0) {
        roomWidth++;
        rooms[nr][nc] = roomNumber;
        queue.push({ r: nr, c: nc });
      }
    }
  }

  return roomWidth;
}

function fillAdjacent(r, c, rooms, adjacentData) {
  let dr = [0, -1, 0, 1];
  let dc = [-1, 0, 1, 0];

  for (let d = 0; d < 4; d++) {
    const nr = r + dr[d];
    const nc = c + dc[d];

    if (
      nr < 0 ||
      nc < 0 ||
      rooms.length <= nr ||
      rooms[r].length <= nc ||
      rooms[nr][nc] == rooms[r][c]
    )
      continue;

    adjacentData[rooms[r][c]][rooms[nr][nc]] = true;
  }
}

function processCastleData(N, M, castle) {
  const nrange = [...Array.from(Array(N))];
  const mrange = [...Array.from(Array(M))];
  const rooms = mrange.map((_) => nrange.map((_) => -1));
  let castleData = [];
  let roomNumber = 0;
  
  for (let i = 0; i < M; i++)
    for (let j = 0; j < N; j++)
      if (rooms[i][j] < 0) {
        const roomWidth = fillRoom(i, j, roomNumber++, rooms, castle);
        castleData.push(roomWidth);
      }

  const range = [...Array.from(Array(roomNumber))];
  let adjacentData = range.map((_) => range.map((_) => false));

  for (let i = 0; i < M; i++)
    for (let j = 0; j < N; j++) 
      fillAdjacent(i, j, rooms, adjacentData);

  return { castleData, adjacentData };
}

function getMaximumWidthAtBroken(castleData, adjacentData) {
  let maxWidth = castleData[0];

  for (let i = 0; i < castleData.length; i++) {
    for (let j = 0; j < castleData.length; j++) {
      if (i == j) continue;
      if (adjacentData[i][j])
        maxWidth = Math.max(maxWidth, castleData[i] + castleData[j]);
    }
  }

  return maxWidth;
}

function solution(N, M, castle) {
  const { castleData, adjacentData } = processCastleData(N, M, castle);

  console.log(castleData.length);
  console.log(Math.max(...castleData));
  console.log(getMaximumWidthAtBroken(castleData, adjacentData))
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  const [N, M] = input[0].split(" ").map(Number);
  let castle = [];
  for (let i = 1; i < input.length; i++)
    castle.push(input[i].split(" ").map(Number));
  solution(N, M, castle);
})();
