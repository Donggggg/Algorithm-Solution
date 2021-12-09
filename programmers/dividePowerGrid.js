function toGraph(n, wires) {
    const graph = [...Array.from(Array(n))].map(e => []);
    
    for (let i = 0; i < wires.length; i++) {
        const first = wires[i][0] - 1;
        const second = wires[i][1] - 1;
        graph[first].push(second);
        graph[second].push(first);
    }
    
    return graph;
}

function countTotalNode (first, second, graph) {
    let visits = [...Array.from(Array(graph.length))].map(e => false);
    let queue = [];
    let count = 0;
    queue.push(first);
    visits[first] = true;
    
    while(queue.length > 0) {
        const node = queue.shift();
        count++;
        
        for (let i = 0; i < graph[node].length; i++) {
            const nextNode = graph[node][i];
            
            if (visits[nextNode] || 
                (node === first && nextNode === second) || 
                (node === second && nextNode === first)) continue;
            
             visits[nextNode] = true;
            queue.push(nextNode);
        }
    }
    
    return count;
}

function solution(n, wires) {
    const calculateDiff = (wire, graph) => 
        Math.abs(countTotalNode(wire[0] - 1, wire[1] - 1, graph) - countTotalNode(wire[1] - 1, wire[0] - 1, graph));
    const graph = toGraph(n, wires);
    let minDiff = 100;
    
    for(let i = 0; i < wires.length; i++) 
        minDiff = Math.min(calculateDiff(wires[i], graph), minDiff);
    
    return minDiff;
}