const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];
const ROTATE_NUM = 4;

function getChunks(baseY, baseX, table, visits, type) {
  const blockFlag = type === "PUZZLE" ? 0 : 1;
  const { length } = table;
  let queue = [];
  let frag = [];
  visits[baseY][baseX] = true;
  queue.push({ x: baseX, y: baseY });

  while (queue.length > 0) {
    const cur = queue.shift();
    frag.push({ x: cur.x - baseX, y: cur.y - baseY });

    for (let i = 0; i < ROTATE_NUM; i++) {
      const nx = cur.x + dx[i];
      const ny = cur.y + dy[i];

      if (
        nx < 0 ||
        ny < 0 ||
        length <= nx ||
        length <= ny ||
        visits[ny][nx] ||
        table[ny][nx] === blockFlag
      )
        continue;

      queue.push({ x: nx, y: ny });
      visits[ny][nx] = true;
    }
  }
  return frag;
}

function getFrags(table, type) {
  const blockFlag = type === "PUZZLE" ? 0 : 1;
  const { length } = table;
  const range = [...Array.from(Array(length))];
  const visits = range.map((_) => range.map((_) => false));
  let frags = [];

  for (let i = 0; i < length; i++)
    for (let j = 0; j < length; j++)
      if (table[i][j] !== blockFlag && !visits[i][j])
        frags.push(getChunks(i, j, table, visits, type));

  return frags;
}

function rotatePuzzle(puzzle) {
  const rotated = puzzle
    .map((frag) => {
      return { x: frag.y, y: -frag.x };
    })
    .sort((a, b) => {
      if (a.y - b.y != 0) return a.y - b.y;
      return a.x - a.x;
    });
  return rotated.map((frag) => {
    return { x: frag.x + -rotated[0].x, y: frag.y + -rotated[0].y };
  });
}

function match(puzzle, blank) {
  if (puzzle.length !== blank.length) return false;
  return blank.every((square) =>
    puzzle.some((frag) => frag.x === square.x && frag.y === square.y)
  );
}

function getCoverage(puzzles, blanks) {
  let coverage = 0;

  for (let i = 0; i < blanks.length; i++) {
    const blank = blanks[i];

    for (let j = 0; j < puzzles.length; j++) {
      let puzzle = puzzles[j];
      let isMatch = false;

      for (let r = 0; r < ROTATE_NUM; r++) {
        puzzle = rotatePuzzle(puzzle);
        if (match(puzzle, blank)) {
          isMatch = true;
          puzzles.splice(j, 1);
          break;
        }
      }

      if (isMatch) {
        coverage += puzzle.length;
        break;
      }
    }
  }

  return coverage;
}

function solution(gameBoard, table) {
  const puzzles = getFrags(table, "PUZZLE");
  const blanks = getFrags(gameBoard, "GAME");
  return getCoverage(puzzles, blanks);
}
