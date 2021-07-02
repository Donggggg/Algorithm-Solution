#include <iostream>
#include <queue>
#include <utility>
#define MAX 1000
using namespace std;

int N, M;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
queue<pair<int,int>> q;
pair<int,int> cur;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int x, y, nx, ny, answer = 0;

    cin >> M >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            // 첫 입력 시 토마토 위치 체크 및 큐 삽입
            if(arr[i][j] == 1) {
                q.push(make_pair(i,j));
                visit[i][j] = true;
            }
        }

    while(!q.empty())
    {
        int range = q.size(); // answer째날 영향을 줄 토마토 개수
        while(range--)
        {
            cur = q.front(); q.pop();
            x = cur.first; y = cur.second;

            for(int i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];

                // 종료 조건
                if(nx < 0 || ny < 0 || N <= nx || M <= ny || visit[nx][ny] || arr[nx][ny] == -1)
                    continue;

                // 익은 토마토 처리
                arr[nx][ny] = 1;
                visit[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
        answer++; // 날짜 증가
    }

    // 익지 않은 토마토가 있는지 체크
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++) 
            if(arr[i][j] == 0)
                answer = 0;

    cout << answer-1 << "\n";
    return 0;
}