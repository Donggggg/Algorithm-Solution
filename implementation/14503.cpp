#include <iostream>
#include <vector>
using namespace std;
#define MAX 50
#define DIRS 4
#define DIRTY 0
#define WALL 1
#define CLEAN 2

int N, M;
int r, c, d, ans;
int dr[DIRS] = {-1, 0, 1, 0}, dc[DIRS] = {0, 1, 0, -1};
int room[MAX][MAX];

void clean() {
    if(room[r][c] != CLEAN) {
        room[r][c] = CLEAN;
        ans++;
    }
}

int detect() {
    int nr = r + dr[d];
    int nc = c + dc[d];

    if(room[nr][nc] == WALL || room[nr][nc] == CLEAN) 
        return -1;

    r = nr;
    c = nc;

    return 0;
}

int check() {
    int rdir = (d + 2) % DIRS;
    int nr = r + dr[rdir];
    int nc = c + dc[rdir];

    if(room[nr][nc] == WALL)
        return -1;
    
    r = nr;
    c = nc;

    return 0;
}

void solve() {
    while(1)
    {
        bool done = false;
        clean();
        
        for(int i = 0; i < DIRS; i++) {
            d = d - 1 < 0 ? 3 : d - 1;

            if(detect() == 0) {
                done = true;
                break;
            }
        }

        if(!done && check() < 0) break;
    }

    cout << ans << '\n';
}

int main() {
    int x;

    cin >> N >> M;
    cin >> r >> c >> d;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> x;
            room[i][j] = x;
        }
    }

    solve();

    return 0;
}