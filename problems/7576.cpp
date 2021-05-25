#include <iostream>
#include <memory.h>
using namespace std;
#define MAX 2500
#define DIRECTS 4

int T, M, N, K;
int field[MAX][MAX];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void eraseGroup(int x, int y)
{
    int nx, ny;

    field[x][y] = 0;
    
    for(int i = 0; i < DIRECTS; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx < 0 || ny < 0 || N <= nx || M <= ny || field[nx][ny] == 0)
            continue;

        eraseGroup(nx, ny);
    }
}

int main()
{
    int x, y, worm;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> T;

    while(T--)
    {
        cin >> M >> N >> K;
        worm = 0;
        memset(field, 0, MAX * MAX * sizeof(int));

        for(int i = 0; i < K; i++) {
            cin >> x >> y;
            field[y][x] = 1;
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++) {
                if(field[i][j] == 1) {
                    eraseGroup(i, j);
                    worm++;    
                }
            }
            
        cout << worm << "\n";
    }
    return 0;
}