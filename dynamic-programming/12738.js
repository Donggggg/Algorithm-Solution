Array.prototype.lowerBound = function (target) {
    let left = 0;
    let right = this.length - 1;
    let idx = this.length;
  
    while (left <= right) {
      let mid = Math.floor((right + left) / 2);
  
      if (target <= this[mid]) {
        right = mid - 1;
        idx = Math.min(mid, idx);
      } else if (target > this[mid]) left = mid + 1;
    }
  
    return idx;
  };
  
  function solution(N, arr) {
    let list = [];
  
    for (let i = 0; i < arr.length; i++) {
      let index = list.lowerBound(arr[i]);
      if (index == list.length) list.push(arr[i]);
      else list[index] = arr[i];
    }
  
    console.log(list.length);    
  }
  
  (function () {
    let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
    input = input
      .slice(0, input.length - 1)
      .map((line) => line.replace("\r", ""));
    solution(
      Number(input[0]),
      input[1].split(" ").map((e) => Number(e))
    );
  })();
  