function print(matrix, state) {
    matrix.slice(0, state.r).forEach((line) => {
        const pr = line.reduce((acc, cur, idx) => {
            if(state.c <= idx) return acc;
            return `${acc}${cur} `;
        },"");
        console.log(pr);
    });
    
}
const MAX = 100;
const range = [...Array.from(Array(MAX))];

function getMap(arr) {
  let map = range.map((_) => range.map((_) => 0));

  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr[i].length; j++) {
      if (MAX <= i || MAX <= j) continue;
      map[i][j] = arr[i][j];
    }
  }

  return map;
}

function translateToColumn(matrix, c, row) {
  let column = [];
  for (let r = 0; r < row; r++) column.push(matrix[r][c]);
  return column;
}

function translate(matrix) {
  let newMatrix = [];
  let array = [];

  for (let i = 0; i < matrix.length; i++) {
    array = [];
    for (let j = 0; j < matrix.length; j++) {
      if (i < matrix[j].length) array.push(matrix[j][i]);
      else array.push(0);
    }
    newMatrix.push(array);
  }
  return newMatrix;
}

function operate(line) {
  let idx = 0;
  let table = {};
  let order = [];

  while (idx < line.length) {
    if (line[idx] == 0) {
      idx++;
      continue;
    }
    if (table[line[idx]] == undefined) table[line[idx]] = 1;
    else table[line[idx]]++;
    idx++;
  }

  for (let key in table) order.push({ n: Number(key), cnt: table[key] });
  order.sort((a, b) => (a.cnt == b.cnt ? a.n - b.n : a.cnt - b.cnt));
  return order.map((item) => [item.n, item.cnt]).flat();
}

function operateR(map, state) {
  let result = [];
  let maxLen = 0;

  for (let i = 0; i < state.r; i++) {
    result.push(operate(map[i]));
    maxLen = Math.max(result[result.length - 1].length, maxLen);
  }

  state.c = maxLen;

  return { newMatrix: getMap(result), newState: state };
}

function operateC(map, state) {
    let result = [];
    let maxLen = 0;

  for (let i = 0; i < state.c; i++) {
    const column = translateToColumn(map, i, state.r);
    result.push(operate(column));
    maxLen = Math.max(result[result.length - 1].length, maxLen);
  }

  state.r = maxLen;

  console.log(result, translate(result))

  return {newMatrix: getMap(translate(result)), newState: state};
}

function operateRC(map, state) {
  const { newMatrix, newState } =
    state.r >= state.c ? operateR(map, state) : operateC(map, state);
  state = newState;
  return newMatrix;
}

function solution(r, c, k, arr) {
  let state = { r: 3, c: 3 };
  let time = 0;

  let map = getMap(arr, state);

  while (time <= 100) {
    if (map[r - 1][c - 1] == k) {
      console.log(time);
      return;
    }
    map = operateRC(map, state);
    print(map, state);
    console.log(' ')
    time++;
  }

  console.log(-1);
}

(function () {
  let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
  input = input
    .slice(0, input.length - 1)
    .map((line) => line.replace("\r", ""));

  const [r, c, k] = input[0].split(" ").map(Number);
  let arr = [];
  for (let i = 1; i < input.length; i++)
    arr.push(input[i].split(" ").map(Number));
  solution(r, c, k, arr);
})();
