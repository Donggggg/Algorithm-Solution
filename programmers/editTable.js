class Node {
    constructor(num) {
        this.num = num;
        this.next = null;
        this.prev = null;
    }
}

let head;
let cur;

function initNode(n, k) {
    head = new Node(0);
    cur = head;
    let curNode = head;
        
    for(let i = 1; i < n; i++) {
        let nextNode = new Node(i);
        nextNode.prev = curNode;
        curNode.next = nextNode;
        curNode = curNode.next;
        if(i === k) cur = curNode;
    }        
}

function movePointer(k) {
    if(k < 0) {
        while(k++ < 0 && cur.prev) cur = cur.prev;
    } else {
        while(k-- && cur.next) cur = cur.next;
    }
}

function deleteNode () {
    let tempNode = cur;
    
    if(cur.next && cur.prev) {
        cur.prev.next = cur.next;
        cur.next.prev = cur.prev;
        cur = cur.next;
    } else if(cur.prev) {
        cur.prev.next = null;
        cur = cur.prev;
    } else if(cur.next) {
        cur.next.prev = null;
        cur = cur.next;
    }
    
    return tempNode;
}

function recoverNode(tempNode) {
    let curNode = tempNode;
    
    if(curNode.prev) 
        curNode.prev.next = curNode;
    
    if(curNode.next) 
        curNode.next.prev = curNode;
}

function getDiffTable(history, n) {
    let table = [...Array.from(Array(n))].map((_) => 'O');
    history.forEach(node => table[node.num] = 'X');
    return table.join('');
}

function solution(n, k, cmd) {
    let history = [];
    initNode(n, k);
    
    for(let i = 0; i < cmd.length; i++) {
        const cmset = cmd[i].split(' ');
        
        switch(cmset[0]) {
            case 'U' :
                movePointer(-cmset[1]);
                break;
            case 'D' :
                movePointer(cmset[1]);
                break;
            case 'C' :
                history.push(deleteNode());
                break;
            case 'Z' :
                recoverNode(history.pop());
                break;
        }
    }
    
    return getDiffTable(history, n);
    
}