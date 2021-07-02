#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000000

string tmp;
int N;
int map[50][50], wall[50][50];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
queue<pair<int,int>> q;
pair<int,int> cur;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        for(int j = 0; j < tmp.length(); j++)
            map[i][j] = tmp[j] - '0';
    }

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++)
            wall[i][j] = MAX;

    wall[0][0] = 0;
    q.push(make_pair(0,0));

    while(!q.empty()) {
        cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
            printf("[%d][%d] = %d\n", x, y, wall[x][y]);
            for(int i =0;i<N;i++){
                for(int j =0;j<N;j++){
                    printf("%d ", wall[i][j]);
                                    }
                printf("\n");
            }

        for(int i = 0; i < 4; i++) {
            int nx = x+dx[i], ny = y+dy[i];

            if(nx > -1 && ny > -1 && nx < N && ny < N) {
                if(map[nx][ny] == 0) {
                    if(wall[nx][ny] > wall[x][y]+1) {
                        wall[nx][ny] = wall[x][y] + 1;
                        q.push(make_pair(nx,ny));
                    }
                }
                 else if(map[nx][ny] == 1) {
                    if(wall[nx][ny] > wall[x][y]) {
                        wall[nx][ny] = wall[x][y];
                        q.push(make_pair(nx,ny));
                    }
                 }
            }
        }
    }
    
    cout << wall[N-1][N-1] << "\n";

    return 0;
}