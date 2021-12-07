function solution(price, money, count) {    
    const total = [...Array.from(Array(count))].reduce((acc,_,idx) => acc + price * (idx + 1), 0);
    return total < money ? 0 : total - money;
}