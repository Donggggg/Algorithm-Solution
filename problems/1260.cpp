#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
 
#define MAX 1001            
int N, M, V;                   
int matrix[MAX][MAX] = {0, }; // 인접 행렬 표시 방식
int visit[MAX] = {0, };

void dfs(int v)
{
    cout << v << ' ';
    visit[v] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (visit[i] == 1 || matrix[v][i] == 0)
            continue;
        dfs(i);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visit[v] = 1;

    while(!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << ' ';

        for(int i = 1; i <= N; i++) {
            if(visit[i] == 1 || matrix[v][i] == 0)
                continue;

            q.push(i);
            visit[i] = 1;
        }
    }
}
 
int main() {
    int x, y;
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++) {   
        cin >> x >> y;             
        matrix[x][y] = matrix[y][x] = 1;    
    }
    dfs(V);            
    cout << '\n';
    memset(visit, 0, MAX * sizeof(int));
    bfs(V);
    cout << '\n';
    return 0;
}