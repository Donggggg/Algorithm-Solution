#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000

int N, ans, sharkWeight, sharkStomach;
int map[20][20], dis[20][20], visit[20][20];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
queue<pair<int,int>> q;
pair<int,int> shark;

void reset() 
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            dis[i][j] = 0;
            visit[i][j] = false;
        }
    while(!q.empty())   q.pop();
}

void searchDis()
{
    int x, y, nx, ny;
    pair<int,int> pos;

    while(!q.empty()) {
        pos = q.front(); q.pop();
        x = pos.first; y = pos.second;

        for(int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];

            if(visit[nx][ny] || sharkWeight < map[nx][ny]) // 유망도 검사인데 개고생(2) : 멍청하게 다익스트라 적용했다가 메모리 초과..
                continue;

            if(nx > -1 && nx < N && ny > -1 && ny < N ) {
                dis[nx][ny] = dis[x][y] + 1;
                visit[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int eatFish()
{
    int minDis = INF;
    bool isAte = false;
    pair<int,int> pos;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // 빈 자리이거나 더 무거운 물고기면 안 먹음
            if(map[i][j] == 0 || map[i][j] >= sharkWeight)
                continue;

            // 현재 최소거리보다 작고 물고기가 있으면 먹음
            if(dis[i][j] < minDis && map[i][j] != 0) {
                pos.first = i; pos.second = j;
                minDis = dis[i][j];
                isAte = true;
            }
        }
    }

    // 먹을 물고기가 없으면 종료
    if(!isAte) 
        return -1;
    
    // 물고기를 먹은 경우 처리
    ans += minDis;
    shark = pos;
    map[shark.first][shark.second] = 0; // 개고생(3) : 물고기 없어지면 비워야지....
    sharkStomach++;
    
    // 먹은 물고기가 현재 무게와 같으면 사이즈 증가
    if(sharkStomach == sharkWeight) {
        sharkWeight++;
        sharkStomach = 0;
    }

    return 0;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) 
                shark = make_pair(i,j);
        }

    sharkWeight = 2;
    sharkStomach = 0;
    map[shark.first][shark.second] = 0; // 개고생(1) : 처음 상어의 위치를 비워야지....

    while(1)
    {
        reset();
        visit[shark.first][shark.second] = 1;
        q.push(shark);
        searchDis();
       
        if(eatFish() < 0) 
            break;
    }

    cout << ans << '\n';

    return 0;
}