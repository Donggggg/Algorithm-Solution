#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25
#define DIRECTS 4
using namespace std;

int N, tag;
int map[MAX][MAX];
vector<int> buildings; // buildings[단지 넘버 - 2] = 단지의 개수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    int nx, ny; // 새로 이동할 곳의 좌표
    buildings[buildings.size()-1] += 1; // 해당 단지의 가구수 + 1
    map[x][y] = tag;
    
    // 상,하,좌,우 검사
    for(int i = 0; i < DIRECTS; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        // 범위를 벗어나는 경우 스킵
        if(nx < 0 || ny < 0 || N <= nx || N <= ny)
            continue;

        if(map[nx][ny] == 1) {
            dfs(nx,ny);
        }
    }
}

int main()
{
    tag = 2;
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%1d", &map[i][j]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 1) {
                buildings.push_back(0);
                dfs(i, j);
                tag++;
            }
        }

    sort(buildings.begin(), buildings.end());

    cout << buildings.size() << '\n';
    for(auto item : buildings) {
        cout << item << '\n';
    }
    
    return 0;
}