#include <iostream>
#include <memory.h>
#include <queue>
#include <utility>
#define MAX 51
using namespace std;

int T, M, N, K;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void eraseGroup(int i, int j)
{
    queue<pair<int,int>> q;
    pair<int,int> cur;
    int x, y, nx, ny;

    q.push(make_pair(i,j));
    visit[i][j] = true;

    while(!q.empty())
    {
        cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;

        for(int i = 0; i < 4; i++) {
            // 다음 이동할 좌표
            nx = x + dx[i];
            ny = y + dy[i];

            // 종료조건
            if(nx < 0 || ny < 0 || N <= nx || M <= ny || visit[nx][ny] || map[nx][ny] != 1)
                continue;

            visit[nx][ny] = true;
            map[nx][ny] = 0;
            q.push(make_pair(nx,ny));
        }
    }
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int x, y, worm;
    cin >> T;

    while(T--)
    {
        cin >> M >> N >> K; // 입력 받음
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        worm = 0;

        for(int i = 0; i < K; i++) {
            cin >> x >> y;
            map[y][x] = 1; // 배추 위치에 1 세팅
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(map[i][j] == 1) {
                    eraseGroup(i, j);
                    worm++;
                }

        cout << worm << '\n';
    }

    return 0;
}