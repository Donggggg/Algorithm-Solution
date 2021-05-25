#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define DIRECTS 4

int N, tag;
int map[25][25];
vector<int> buildings;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void makeGroup(int x, int y)
{
    int nx, ny;
    map[x][y] = tag;
    *(buildings.end()-1) += 1;

    for(int i = 0; i < DIRECTS; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx < 0 || ny < 0 || 25 <= nx || 25 <= ny)
            continue;
        if(map[nx][ny] == 1)
            makeGroup(nx,ny);
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
                makeGroup(i, j);
                tag++;
            }
        }

    cout << buildings.size() << '\n';
    sort(buildings.begin(), buildings.end());
    for(int item : buildings)
        cout << item << '\n';

    return 0;
}