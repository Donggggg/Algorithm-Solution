#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

typedef struct _pos {
    int x;
    int y;
} Position;

int N, M, ans=99999999, totalDis;
int arr[51][51] = {0,};
int after[51][51] = {0,};
Position pos;
vector<Position> chickenStoreList;
Position currentList[13];

void goOutBusiness()
{
    // 0과 1먼저 복사
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) {
            after[i][j] = arr[i][j];
            if(arr[i][j] == 2) 
                after[i][j] = 0;
        }

    // 운영하는 치킨집 좌표 복사
    for(int i = 0 ; i < M; i++) 
        after[currentList[i].x][currentList[i].y] = 2;
}

void getChickenDistance() 
{
    int dx[4] = {1, -1, 0, 0}, nx;
    int dy[4] = {0, 0, 1, -1}, ny;
    int visit[51][51];
    queue<Position> q;

    goOutBusiness(); // 새로운 지도 생성
    memset(visit, 0, sizeof(visit));

    for(int a = 0; a < M; a++) {
        int i = currentList[a].x, j = currentList[a].y;
        // 치킨집 위치면 bfs
        if (after[i][j] == 2) {
            pos.x = i;
            pos.y = j;
            q.push(pos);
            visit[i][j] = 1;

            while (!q.empty())
            {
                pos = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    nx = pos.x + dx[k];
                    ny = pos.y + dy[k];

                    // 방문조건 : 방문하지 않았거나 더 짧은 거리가 있는 경우
                    if ((nx > 0 && nx <= N && ny > 0 && ny <= N) && (visit[nx][ny] == 0 || visit[nx][ny] > visit[pos.x][pos.y] + 1))
                    {
                        Position tmp;
                        visit[nx][ny] = visit[pos.x][pos.y] + 1;
                        tmp.x = nx; tmp.y = ny;
                        q.push(tmp);
                    }
                }
            }
        }
    }
    // 집마다 치킨거리 합 구함
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (after[i][j] == 1)
                totalDis += visit[i][j] - 1;
}

void setManageList(int depth, int next)
{
    // 완성되면 치킨거리 계산
     if(depth == M) {
         totalDis = 0;
         getChickenDistance();
         ans = min(ans, totalDis);
         return;
    }

    // 조합 채워나감
    for (int i = next; i <= chickenStoreList.size(); i++) {
        pos = chickenStoreList[i-1];
        currentList[depth] = pos;
        setManageList(depth+1, i + 1);
    }
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) {
                pos.x = i; pos.y = j;
                chickenStoreList.push_back(pos);
            }
        }

    setManageList(0, 1); // 가능한 케이스 세팅

    cout << ans << '\n';

    return 0;
}