function solution(N, arr) {
    let list = [...Array.from(Array(N))].map((_) => 1);

    for(let i = 1; i < N; i++) 
        for(let j = 0; j < i; j++) 
            if(arr[j] < arr[i]) 
                list[i] = Math.max(list[j] + 1, list[i]);

    console.log(list.sort((a,b) => b - a)[0]);
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
