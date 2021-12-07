const initialVisitState = [...Array.from(Array(dungeons.length))].map(() => false);
const getExploredDungeonNumber = (visitState) => visitState.reduce((acc,cur) => acc + cur, 0);

function exploreDungeon (state, targetDungeon, dungeons) {
    if(state.visitState[targetDungeon] || 
       state.n < dungeons[targetDungeon][0]) return ;
    
    let newVisitState = [...state.visitState];
    newVisitState[targetDungeon] = true;
    const newState = { n: state.n - dungeons[targetDungeon][1], visitState: newVisitState };
    return newState;
}


function solution(k, dungeons) {    
    let answer = -1;
    let queue = [];
    
    for(let i = 0; i < dungeons.length; i++) 
        queue.push(exploreDungeon({ n: k, visitState: [...initialVisitState] }, i, dungeons));
    
    
    while(queue.length) {
        const currentState = queue.shift();
        answer = Math.max(getExploredDungeonNumber(currentState.visitState), answer);
        
        for(let i = 0; i < dungeons.length; i++) {
            const targetState = exploreDungeon(currentState, i, dungeons);
            if (targetState) queue.push(targetState);
        }
    }

    return answer;
}