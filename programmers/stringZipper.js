function solution(s) {    
    let word;
    let cnt;
    let answer = 1001;
    let zipped;
    let pos;
    
    for(let len = 1; len <= s.length; len++) {   
        word = "";
        cnt = 1;
        zipped = "";
        pos = 0;
        
        while(true) {
            const nextWord = s.slice(pos, pos+len);
            
            if(word == nextWord) cnt++;
            else {
                zipped += `${cnt == 1 ? '' : cnt}${word}`;
                cnt = 1;
            }
            
            word = nextWord;
            
            if(s.length < pos) break;
            
            pos += len;
        }
        answer = Math.min(answer, zipped.length);
    }
    
    return answer;
}