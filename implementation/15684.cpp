#include <iostream>
#include <vector>
using namespace std;

#define P pair<int,int>
#define MAX_HEIGHT 30
#define MAX_WIDTH 10

int N, M, H;
int ladder[MAX_HEIGHT+1][MAX_WIDTH], newLadder[MAX_HEIGHT+1][MAX_WIDTH];
vector<P> cnd;

bool setNewLadder(int i, int j, int k) {
    for(int w = 0; w <= N; w++) 
        for(int h = 0; h <= H; h++) 
            newLadder[h][w] = ladder[h][w];

    if(0 <= i) {
        newLadder[cnd[i].first][cnd[i].second] = cnd[i].second + 1;
        newLadder[cnd[i].first][cnd[i].second + 1] = cnd[i].second;
    }
    if (0 <= j) {
        if(newLadder[cnd[j].first][cnd[j].second] != 0 || newLadder[cnd[j].first][cnd[j].second + 1] != 0)
            return false;
        newLadder[cnd[j].first][cnd[j].second] = cnd[j].second + 1;
        newLadder[cnd[j].first][cnd[j].second + 1] = cnd[j].second;
    }
    if (0 <= k) {
        if(newLadder[cnd[k].first][cnd[k].second] != 0 || newLadder[cnd[k].first][cnd[k].second + 1] != 0)
            return false;
        newLadder[cnd[k].first][cnd[k].second] = cnd[k].second + 1;
        newLadder[cnd[k].first][cnd[k].second + 1] = cnd[k].second;
    }
    
    return true;
}

bool checkLadderResult() {
    int i, h, cur;

    for(i = 1; i < N; i++) {
        cur = i;

        for(h = 1; h <= H; h++) 
            if(newLadder[h][cur] != 0) 
                cur = newLadder[h][cur];

        if(i != cur) return false;
    }

    return true;
}

void solve() {
    setNewLadder(-1, -1, -1);
     if(checkLadderResult()) {
         cout << 0 << '\n';
         return ;
     }

    for(int i = 0; i < cnd.size(); i++) {
        setNewLadder(i, -1, -1);
        if(checkLadderResult()) {
            cout << 1 << '\n';
            return ;
        }
    }

    for(int i = 0; i < cnd.size(); i++) {
        for(int j = i+1; j < cnd.size(); j++) {
            if(!setNewLadder(i, j, -1)) continue;
            if (checkLadderResult()) {
                cout << 2 << '\n';
                return;
            }
        }
    }

    for(int i = 0; i < cnd.size(); i++) {
        for(int j = i+1; j < cnd.size(); j++) {
            for(int k = j+1; k < cnd.size(); k++) {
                if(!setNewLadder(i, j, k)) continue;
                if (checkLadderResult()) {
                    cout << 3 << '\n';
                    return;
                }
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    int h, p;

    cin >> N >> M >> H;

    for(int i = 0; i < M; i++) {
        cin >> h >> p;
        ladder[h][p] = p + 1;
        ladder[h][p + 1] = p;
    }

    for(int i = 1; i < N; i++) 
        for(int h = 1; h <= H; h++) 
            if(ladder[h][i] == 0 && ladder[h][i+1] == 0)
                cnd.push_back({h, i});

    solve();

    return 0;
}