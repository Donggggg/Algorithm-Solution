#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[101][101], depth[101][101], visit[101][101], N, M;

int main()
{
    int x, y;
    queue<pair<int,int>> queue;
    pair<int,int> pair;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%1d", &arr[i][j]);

    pair.first = 1;
    pair.second = 1;
    depth[1][1] = 1;
    visit[1][1] = 1;
    queue.push(pair);

    while(!queue.empty()) {
        pair = queue.front();
        queue.pop();
        x = pair.first;
        y = pair.second;
        if(x == N && y == M) {
            printf("%d\n", depth[x][y]);
            return 0;
        }

        if(arr[x+1][y] != 0 && x+1 <= N && visit[x+1][y] != 1) {
            pair.first = x+1;
            pair.second = y;
            depth[x+1][y] = depth[x][y] + 1;
            visit[x+1][y] = 1;
            queue.push(pair);
        }
        if(arr[x-1][y] != 0 && x-1 >= 1 && visit[x-1][y] != 1) {
            pair.first = x-1;
            pair.second = y;
            depth[x-1][y] = depth[x][y] + 1;
            visit[x-1][y] = 1;
            queue.push(pair);
        }
        if(arr[x][y+1] != 0 && y+1 <= M && visit[x][y+1] != 1) {
            pair.first = x;
            pair.second = y+1;
            depth[x][y+1] = depth[x][y] + 1;
            visit[x][y+1] = 1;
            queue.push(pair);
        }
        if(arr[x][y-1] != 0 && y-1 >= 1 && visit[x][y-1] != 1) {
            pair.first = x;
            pair.second = y-1;
            depth[x][y-1] = depth[x][y] + 1;
            visit[x][y-1] = 1;
            queue.push(pair);
        }
    }
    
    return 0;
}