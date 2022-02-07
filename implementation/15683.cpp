#include <iostream>
#include <vector>
using namespace std;

#define MAX 8
#define DIRS 4
#define VISIBLE -1
#define EMPTY 0
#define WALL 6

struct CCTV {
    int r;
    int c;
    int type;
};

int N, M, emptyCnt, answer = MAX * MAX;
int room[MAX][MAX], testRoom[MAX][MAX];
vector<CCTV> cctvs;

int getStraightVisivleSpot(int r, int c, int dir) {
    int cnt = 0;
    int dr[DIRS] = {-1, 0, 1, 0}, dc[DIRS] = {0, 1, 0, -1};

    while(1) {
        r += dr[dir];
        c += dc[dir];

        if(r < 0 || c < 0 || N <= r || M <= c || testRoom[r][c] == WALL)
            break;
        
        if(testRoom[r][c] == EMPTY) {
            testRoom[r][c] = VISIBLE;
            cnt++;
        }
    }

    return cnt;
}

int rotateDirection(int dir, int turn) {
    return (dir + turn) % DIRS;
}

int getVisibleSpot(CCTV cctv, int state) {
    int cnt = 0;

    switch (cctv.type) 
    {
    case 1:
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, state);
        break;
    case 2:
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, rotateDirection(state, 1));
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, rotateDirection(state, 3));
        break;
    case 3:
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, state);
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, rotateDirection(state, 1));
        break;
    case 4:
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, state);
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, rotateDirection(state, 1));
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, rotateDirection(state, 3));
        break;
    case 5:
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, state);
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, rotateDirection(state, 1));
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, rotateDirection(state, 2));
        cnt += getStraightVisivleSpot(cctv.r, cctv.c, rotateDirection(state, 3));
        break;
    }

    return cnt;
}

int getBlindSpot(int states[MAX]) {
    int visCnt = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) 
            testRoom[i][j] = room[i][j];

    for(int i = 0; i < cctvs.size(); i++) 
        visCnt += getVisibleSpot(cctvs[i], states[i]);
    
    return emptyCnt - visCnt;
}

void simulateCCTV(int depth, int states[MAX]) {
    if(depth == cctvs.size()) {
        int spots = getBlindSpot(states);
        if(spots < answer) answer = spots;
        return;
    }

    for(int d = 0; d < DIRS; d++) {
        int bd = states[depth];
        states[depth] = d;
        simulateCCTV(depth + 1, states);
        states[depth] = bd;
    }
}

void solve() {
    int states[MAX] = {0, };
    
    simulateCCTV(0, states);

    cout << answer << '\n';
}

int main() { 
    int x;

    cin >> N >> M;

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++) {
            cin >> room[i][j];

            if(room[i][j] != EMPTY && room[i][j] != WALL) 
                cctvs.push_back({i,j,room[i][j]});
            else if (room[i][j] == EMPTY) emptyCnt++;
        }

    solve();

    return 0;
}