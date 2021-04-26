#include <iostream>
#include <algorithm>
#include <utility>
using namespace std; 

int N, ans = 0;
int arr[501][501];
int dis[501][501] = {0,};
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int getMaxDistance(int x, int y)
{
    if(dis[x][y]) return dis[x][y];

    int mx = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx > 0 && ny > 0 && nx <= N && ny <= N)
            if (arr[nx][ny] > arr[x][y])
                mx = max(mx, getMaxDistance(nx, ny));
    }

    return dis[x][y] = mx + 1;
}

int main()
{
    // cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) 
            cin >> arr[i][j];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(dis[i][j] != 0)
                continue;
            dis[i][j] = getMaxDistance(i, j);
            ans = max(dis[i][j], ans);
        }
    }

    cout << ans << '\n';

    return 0;
}