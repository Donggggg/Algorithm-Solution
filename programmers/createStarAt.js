const MAX = 1e15;

function getXY(line1, line2) {
    const common = (line1[0] * line2[1]) - (line1[1] * line2[0]);
    const xHead = ((line1[1] * line2[2]) - (line1[2] * line2[1]));
    const yHead = ((line1[2] * line2[0]) - (line1[0] * line2[2]));
    if (common === 0 || xHead % common !== 0 || yHead % common !== 0) return { x: null, y: null };
    const x = xHead / common;
    const y = yHead / common;
    return { x, y };
}

function getDots (line) {
    const max = line.length;
    let minX = MAX;
    let minY = MAX;
    let maxX = -MAX;
    let maxY = -MAX;
    let dots = [];
    
    for (let i = 0; i < max; i++) {
        for (let j = i + 1; j < max; j++) {
            const { x, y } =  getXY(line[i], line[j]);
            if (x === null) continue;
            dots.push({ x, y });
            
            minX = Math.min(minX, x);
            minY = Math.min(minY, y);
            maxX = Math.max(maxX, x);
            maxY = Math.max(maxY, y);
        }
    } 
    
    return { dots, minX, minY, maxX, maxY };
}

function solution(line) {
    const { dots, minX, minY, maxX, maxY } = getDots(line);
    
    let list = [];
    for (let y = maxY; minY <= y; y--) {
        let string;
        string = [...Array.from(Array(Math.abs(maxX - minX) + 1))]
            .reduce((acc, _, idx) => 
                   `${acc}${dots.some(dot => dot.x === (idx+minX) && dot.y === y) ? '*' : '.'}` , '');         
        list.push(string);
    }
        
    return list;
}