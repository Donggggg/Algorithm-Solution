#include <iostream>
#include <queue>
#include <memory.h> // #include <cstring>
using namespace std;
 
#define MAX 1001            
int N, M, V;                   
int matrix[MAX][MAX] = {0, }; // 인접 행렬 표시 방식
int visit[MAX] = {0, }; // 방문 여부 체크용 배열

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

void bfs(int V)
{
    queue<int> q;

    q.push(V); // 시작 노드를 큐에 넣는다.
    visit[V] = 1; // 해당 노드를 방문처리 한다.

    while(!q.empty())
    {
        int cur = q.front(); // front() -> 맨앞 값을 리턴
        q.pop(); // pop() -> 맨앞 값을 뺀다.
        cout << cur << ' ';

        for(int i = 1; i <= N; i++) {
            
            // 생략 조건
            if(visit[i] == 1) 
                continue;

            // i 노드와 인접한 경우
            if(matrix[cur][i] == 1) {
                visit[i] = 1; // 방문 체크를 하고
                q.push(i); // 큐에 삽입
            }
        }
    }
}

/*
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
}*/
 
int main() {
    int x, y;
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++) {   
        cin >> x >> y;             
        matrix[x][y] = matrix[y][x] = 1;     
    }
    dfs(V);            
    cout << '\n';

    memset(visit, 0, sizeof(visit));
    bfs(V);
    cout << '\n';
    return 0;
}