function solution(word) {
    const alphaTable = { A: 0, E: 1, I: 2, O: 3, U: 4 };   
    const orderTable = [781, 156, 31, 6, 1];
    let sum = 0;
    
    for (let i = 0; i < word.length; i++) 
        sum += orderTable[i] * alphaTable[word[i]] + 1;
    
    return sum;
}