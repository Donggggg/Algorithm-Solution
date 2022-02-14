let R;
let C;

function spreadDust(r, c, site, nextSite) {
  let dr = [0, 1, -1, 0];
  let dc = [1, 0, 0, -1];
  let targetCnt = 0;

  for (let i = 0; i < 4; i++) {
    let nr = r + dr[i];
    let nc = c + dc[i];

    if (nc < 0 || nr < 0 || C <= nc || R <= nr || site[nr][nc] == -1) continue;

    targetCnt++;
    nextSite[nr][nc] += Math.floor(site[r][c] / 5);
  }

  nextSite[r][c] -= Math.floor(site[r][c] / 5) * targetCnt;
}

function spread(site) {
  let nextSite = [];
  for (let i = 0; i < site.length; i++) nextSite.push([...site[i]]);

  for (let r = 0; r < R; r++) 
    for (let c = 0; c < C; c++) 
      if (0 < site[r][c]) 
        spreadDust(r, c, site, nextSite);

  for (let i = 0; i < site.length; i++) site[i] = [...nextSite[i]];
}

function blowUpside(part, site) {
  let [r, c] = part;
  let next = 0;

  while (true) {
    let nc = c + 1;
    if (C <= nc) break;
    let temp = site[r][nc];
    site[r][nc] = next;
    next = temp;
    c = nc;
  }

  while (true) {
    let nr = r - 1;
    if (nr < 0) break;
    let temp = site[nr][c];
    site[nr][c] = next;
    next = temp;
    r = nr;
  }

  while (true) {
    let nc = c - 1;
    if (nc < 0) break;
    let temp = site[r][nc];
    site[r][nc] = next;
    next = temp;
    c = nc;
  }

  while (true) {
    let nr = r + 1;
    if (part[0] <= nr) break;
    let temp = site[nr][c];
    site[nr][c] = next;
    next = temp;
    r = nr;
  }

}

function blowDownside(part, site) {
  let [r, c] = part;
  let next = 0;

  while (true) {
    let nc = c + 1;
    if (C <= nc) break;
    let temp = site[r][nc];
    site[r][nc] = next;
    next = temp;
    c = nc;
  }

  while (true) {
    let nr = r + 1;
    if (R <= nr) break;
    let temp = site[nr][c];
    site[nr][c] = next;
    next = temp;
    r = nr;
  }

  while (true) {
    let nc = c - 1;
    if (nc < 0) break;
    let temp = site[r][nc];
    site[r][nc] = next;
    next = temp;
    c = nc;
  }

  while (true) {
    let nr = r - 1;
    if (nr <= part[0]) break;
    let temp = site[nr][c];
    site[nr][c] = next;
    next = temp;
    r = nr;
  }
}

function getTotalDust(site) {
  return site.reduce((acc, cur) => acc + cur.reduce((ac, cr) => cr > 0 ? ac + cr : ac, 0), 0);
}

function solution(T, cleaner, site) {
  R = site.length;
  C = site[0].length;

  while (T--) {
    spread(site);
    blowUpside(cleaner[0], site);
    blowDownside(cleaner[1], site);
  }
    console.log(getTotalDust(site));
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  let [R, C, T] = input[0].split(" ").map((e) => Number(e));
  let site = [];
  let cleaner = [];
  for (let i = 1; i < input.length; i++)
    site.push(
      input[i].split(" ").map((e, j) => {
        if (e == -1) cleaner.push([i-1, j]);
        return Number(e);
      })
    );
  solution(T, cleaner, site);
})();
