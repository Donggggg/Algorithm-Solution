let cnt = 0;
function getWeapon(r, c, type, arr) {
  let newArr = [];
  for (let i = 0; i < arr.length; i++) newArr.push([...arr[i]]);
  const weaponType = [0, -1, 1, 0, -1, 0, 0, -1, -1, 0, 0, 1, 0, 1, 1, 0];
  let power = newArr[r][c] * 2;
  newArr[r][c] = -1;

  for (let i = 0; i < 2; i++) {
    const nr = r + weaponType[type * 4 + i * 2];
    const nc = c + weaponType[type * 4 + i * 2 + 1];

    if (nr < 0 || nc < 0 || arr.length <= nr || arr[0].length <= nc)
      return false;
    if (newArr[nr][nc] < 0) return false;

    power += newArr[nr][nc];
    newArr[nr][nc] = -1;
  }

  return { power, newArr };
}

function getMaximumPower() {
  let maxPower = 0;
  const range = [...Array.from(Array(5))];
  let visit = range.map((_)=>range.map((_)=>false));

  return {
    execute: function (r, c, power, arr) {
        cnt++;
        // if(cnt < 100) 
        // console.log(r,c, power, arr);
      for (let i = 0; i < 4; i++) {
        const { power: cp, newArr } = getWeapon(r, c, i, arr);

        if (!newArr) continue;

        maxPower = Math.max(power + cp, maxPower);

        for (let nr = 0; nr < arr.length; nr++)
          for (let nc = 0; nc < arr[0].length; nc++)
            if (newArr[nr][nc] > 0 && !visit[nr][nc]) {
                // visit[nr][nc] = true;
                this.execute(nr, nc, power + cp, newArr);
                // visit[nr][nc] = false;
            }
      }
    },
    get: function () {
      console.log(maxPower);
    },
    validate: function(r, c) {
        return !visit[r][c];
    }
  };
}

function solution(N, M, arr) {
  const maxPower = getMaximumPower();
  for (let r = 0; r < N; r++)
    for (let c = 0; c < M; c++) {
        if(maxPower.validate(r,c))
        maxPower.execute(r, c, 0, arr);
    }
  maxPower.get();
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  const [N, M] = input[0].split(" ").map(Number);
  let arr = [];
  for (let i = 1; i < input.length; i++)
    arr.push(input[i].split(" ").map(Number));
  solution(N, M, arr);
})();
