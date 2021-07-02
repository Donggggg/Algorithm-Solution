#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, map[100][100], temp[100][100], ans = 9999;
int moves[2] = {1, -1};

void coloringMap(int x, int y, int color) // dfs로 칠하기!
{
    if (map[x][y] == 1)
        map[x][y] = color;
    else
        return;

    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
        {
            if (0 <= moves[i % 2] + x && moves[i % 2] + x <= 100)
                coloringMap(x + moves[i % 2], y, color);
        }
        else
        {
            if (0 <= moves[i % 2] + y && moves[i % 2] + y <= 100)
                coloringMap(x, y + moves[i % 2], color);
        }
    }
}

void labelingIsland()
{
    int color = 2;

    // 한 종류의 섬을 한 숫자로 칠함
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                coloringMap(i, j, color);
                color++;
            }
        }
}

void constructBridge(int x, int y, int color)
{
    queue<pair<int, int> > q;
    pair<int, int> cur;
    int level = 0, length;

    q.push(make_pair(x, y));
    temp[x][y] = -1;

    while (!q.empty()) {
        length = q.size(); 
        for (int a = 0; a < length; a++) {
            cur = q.front(); q.pop();
            x = cur.first; y = cur.second;

            if (temp[x][y] > 1 && temp[x][y] != color) {  
                ans = min(ans, level);
                break;
            }

            for (int i = 0; i < 4; i++) {
                if (i < 2) {
                    if (0 <= moves[i % 2] + x && moves[i % 2] + x < N && temp[moves[i % 2] + x][y] != -1 && temp[moves[i % 2] + x][y] != color) {
                        if(temp[moves[i % 2] + x][y] == 0) temp[moves[i % 2] + x][y] = -1;
                        q.push(make_pair(moves[i % 2] + x, y));
                    }
                }
                else {
                    if (0 <= moves[i % 2] + y && moves[i % 2] + y < N && temp[x][moves[i % 2] + y] != -1 && temp[x][moves[i % 2] + y] != color) {
                        if(temp[x][moves[i%2]+y] == 0) temp[x][moves[i%2]+y] = -1;
                        q.push(make_pair(x, moves[i % 2] + y));
                    }
                }
            }
        }
        level++; // 다리 길이 증가
    }
}

void copyMap()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i][j] = map[i][j];
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    labelingIsland(); // 섬의 종류 구분
    
    // 바다인데 주변이 섬이면 다리 건설 시도
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 0) {
                copyMap();
                if(0 <= i-1 && map[i-1][j] != 0) 
                    constructBridge(i, j, map[i-1][j]);
                else if(i+1 < N && map[i+1][j] != 0)
                    constructBridge(i, j, map[i+1][j]);
                else if(0 <= j-1 && map[i][j-1] != 0)
                    constructBridge(i, j, map[i][j-1]);
                else if(j+1 < N && map[i][j+1] != 0)
                    constructBridge(i, j, map[i][j+1]);
            }
        }

    cout << ans << "\n";

/*
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
*/

    return 0;
}