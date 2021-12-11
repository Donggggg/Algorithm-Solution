const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];

function checkMovable(x, y, ox, oy, dir, rects) {
  if (
    rects.some(
      (rect) => rect[0] < x && rect[1] < y && x < rect[2] && y < rect[3]
    )
  )
    return false;
  if (
    rects.some(
      (rect) =>
        (rect[0] === x && rect[1] <= y && y <= rect[3]) ||
        (rect[2] === x && rect[1] <= y && y <= rect[3]) ||
        (rect[1] === y && rect[0] <= x && x <= rect[2]) ||
        (rect[3] === y && rect[0] <= x && x <= rect[2])
    )
  ) {
    const hx1 = (x + ox) / 2 + (dir < 2 ? 0.5 : 0);
    const hy1 = (y + oy) / 2 + (dir < 2 ? 0 : 0.5);
    const side1 = rects.some(
      (rect) => rect[0] < hx1 && rect[1] < hy1 && hx1 < rect[2] && hy1 < rect[3]
    );
    const hx2 = (x + ox) / 2 + (dir < 2 ? -0.5 : 0);
    const hy2 = (y + oy) / 2 + (dir < 2 ? 0 : -0.5);
    const side2 = rects.some(
      (rect) => rect[0] < hx2 && rect[1] < hy2 && hx2 < rect[2] && hy2 < rect[3]
    );
    if (side1 ^ side2) return true;
  }
  return false;
}

function solution(rectangle, characterX, characterY, itemX, itemY) {
  const length = 51;
  const range = [...Array.from(Array(length))];
  const visits = range.map((_) => range.map((_) => false));
  let queue = [];
  let dis;
  visits[characterY][characterX] = true;
  queue.push({ x: characterX, y: characterY, dis: 0 });

  while (queue.length > 0) {
    const cur = queue.shift();
    if (cur.x === itemX && cur.y === itemY) {
      dis = cur.dis;
      break;
    }

    for (let i = 0; i < 4; i++) {
      const nx = cur.x + dx[i];
      const ny = cur.y + dy[i];

      if (nx < 0 || ny < 0 || length <= nx || length <= ny || visits[ny][nx])
        continue;
      if (!checkMovable(nx, ny, cur.x, cur.y, i, rectangle)) continue;

      visits[ny][nx] = true;
      queue.push({ x: nx, y: ny, dis: cur.dis + 1 });
    }
  }
  return dis;
}
