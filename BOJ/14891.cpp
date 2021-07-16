#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

int K, a, b;
int gear[4][8];

void changePosition(int cur, int dir)
{
    int ori[8];

    for(int i = 0; i < 8; i++)
        ori[i] = gear[cur][i];

    if (dir == 1)
        for (int i = 0; i < 8; i++)
            gear[cur][i] = ori[(i + 7) % 8];
    else
        for (int i = 0; i < 8; i++)
            gear[cur][i] = ori[(i + 1) % 8];
}

void rotateGear(int cur, int dir)
{
    vector<int> clock;

    for (int i = cur + 1, p = cur; i < 4; p++, i++)
        if (gear[p][2] != gear[i][6])
            clock.push_back(i);
        else
            break;
    for (int i = cur - 1, p = cur; 0 <= i; p--, i--)
        if (gear[p][6] != gear[i][2])
            clock.push_back(i);
        else
            break;

    changePosition(cur, dir);

    for(int i = 0; i < clock.size(); i++) {
        if (clock[i] % 2 == cur % 2)
            changePosition(clock[i], dir);
        else
            changePosition(clock[i], -dir);
    }
}

void solve(vector<pair<int,int>> orders)
{
    int cur, dir, scr = 0;

    for(int i = 0; i < K; i++)
    {
        cur = orders[i].first;
        dir = orders[i].second;

        rotateGear(cur, dir);
    }

    // 점수계산하고 출력
    for(int i = 0; i < 4; i++)
        if(gear[i][0] == 1)
            scr += pow(2,i);

    cout << scr << '\n';
}

int main()
{
    vector<pair<int,int>> orders;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 8; j++)
            scanf("%1d", &gear[i][j]);

    cin >> K;

    for(int i = 0; i < K; i++) {
        cin >> a >> b;
        orders.push_back(make_pair(a-1,b));
    }

    solve(orders);

    return 0;
}