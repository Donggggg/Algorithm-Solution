#include <iostream>
using namespace std;
#define INF 1000000

int N, M, cnt;
int graph[501][501] = {0,};
int num[501] = {0,};

void floydWarshall() 
{
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j)
                continue;
            if(graph[i][j] != 1)
                graph[i][j] = INF;
        }
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main()
{
    int a, b;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
    }

    // 플로이드와샬 알고리즘 진행
    floydWarshall(); 

    // 도달 경로가 있으면 num배열에 횟수 기록
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(graph[i][j] != INF && graph[i][j] != 0) {
                num[i]++;
                num[j]++;
            }
        }
    }

    // 주어진 조건에 맞으면 정답 증가
    for(int i = 1; i <= N; i++)
        if(num[i] == N-1)
            cnt++;

    cout << cnt << '\n';

    return 0;
}