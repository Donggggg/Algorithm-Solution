#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
#include <memory.h>
#define START -1

typedef struct _state{
    int r;
    int c;
    int cost;
    int dir;
} state;

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    int arr[25][25];
    int n = board.size();
    queue<state> q;
    state v, nv;
    int dc[4] = {0, 1, 0, -1}, dr[4] = {1, 0, -1, 0};

    for(int i = 0; i < 25; i++)
        for(int j = 0; j < 25; j++)
            arr[i][j] = INT_MAX;
    v.r = 0; v.c = 0;
    v.cost = 0;
    v.dir = START;
    
    q.push(v);
    
    while(!q.empty())
    {
        v = q.front(); q.pop();
        
        if(v.r == n - 1 && v.c == n - 1) 
            answer = min(answer, v.cost);
        
        for(int i = 0; i < 4; i++) {
            int nr = v.r + dr[i];
            int nc = v.c + dc[i];
                        
            if(nr < 0 || nc < 0 || n <= nr || n <= nc || board[nr][nc] == 1)
                continue;
            
            nv.r = nr;
            nv.c = nc;
            nv.dir = i;
            nv.cost = v.cost;
            if(v.dir == i || v.dir == START) 
                nv.cost += 100;
            else
                nv.cost += 600;
            
            // printf(">%d\n", arr[nr][nc]); 
            
            if(nv.cost > arr[nr][nc])
                continue;
            
            arr[nr][nc] = nv.cost;
            q.push(nv);
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return answer;
}