#include <iostream>
#include <vector>
using namespace std;

int M, N, x, y, K;
int map[20][20];
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
vector<int> dice;
vector<int> orders;

void moveDice(int dir)
{
    vector<int> origin = dice;

    switch(dir) {
        case 1 : // 동쪽
            dice[1] = origin[4]; // 위 = 좌
            dice[6] = origin[3]; // 아래 = 우
            dice[4] = origin[6]; // 좌 = 아래
            dice[3] = origin[1]; // 우 = 위
            break;
        case 2 :
            dice[1] = origin[3]; // 위 = 우
            dice[6] = origin[4]; // 아래 = 좌
            dice[4] = origin[1]; // 좌 = 위
            dice[3] = origin[6]; // 우 = 아래
            break;
        case 3 :
            dice[1] = origin[5]; // 위 = 앞
            dice[6] = origin[2]; // 아래 = 뒤
            dice[5] = origin[6]; // 앞 = 아래
            dice[2] = origin[1]; // 뒤 = 위
            break;
        case 4 :
            dice[1] = origin[2]; // 위 = 뒤
            dice[6] = origin[5]; // 아래 = 앞
            dice[5] = origin[1]; // 앞 = 위
            dice[2] = origin[6]; // 뒤 = 아래
            break;
    }
}

void solve()
{
    int nx, ny, n;

    for(int i = 0; i < orders.size(); i++) 
    {
        nx = x + dx[orders[i] - 1];
        ny = y + dy[orders[i] - 1];

        if(nx < 0 || ny < 0 || N <= nx || N <= ny)
            continue;

        moveDice(orders[i]);

        if(map[nx][ny] == 0) {
            map[nx][ny] = dice[6];
        } 
        else {
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }
        
        cout << dice[1] << "\n";
        x = nx;
        y = ny;
    }
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int num;
    dice.assign(7, 0);
    cin >> N >> M >> x >> y >> K;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) 
            cin >> map[i][j];

    for(int i = 0; i < K; i++) {
        cin >> num;
        orders.push_back(num);
    }

    solve();

    return 0;
}