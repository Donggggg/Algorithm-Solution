function getWeapon(r, c, type, arr) {
  const weaponType = [0, -1, 1, 0, -1, 0, 0, -1, -1, 0, 0, 1, 0, 1, 1, 0];
  let newArr = [];
  for (let i = 0; i < arr.length; i++) newArr.push([...arr[i]]);

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

  return {
    execute: function (r, c, power, arr) {
      if (c == arr[0].length) {
        c = 0;
        r++;
      }

      if (r == arr.length) {
        maxPower = Math.max(power, maxPower);
        return;
      }

      if (arr[r][c] != -1) {
        for (let t = 0; t < 4; t++) {
          const { power: cp, newArr } = getWeapon(r, c, t, arr);

          if (!newArr) continue;
          else this.execute(r, c + 1, power + cp, newArr);
        }
      }
      this.execute(r, c + 1, power, arr);
    },
    get: function () {
      console.log(maxPower);
    },
  };
}

function solution(N, M, arr) {
  const maxPower = getMaximumPower();
  maxPower.execute(0, 0, 0, arr);
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
