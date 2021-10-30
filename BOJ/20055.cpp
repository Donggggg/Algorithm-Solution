#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> belt, robotPos;

void rotateBelt()
{
    vector<int> tempBelt, tempRobotPos;
    tempBelt.assign(N*2, 0);
    tempRobotPos.assign(N, 0);
    copy(belt.begin(), belt.end(), tempBelt.begin());
    copy(robotPos.begin(), robotPos.end(), tempRobotPos.begin());

    for(int i = 0; i < N*2; i++) {
        if(i == 0) {
            belt[i] = tempBelt[N*2-1];
            robotPos[0] = 0;
        } else if (0 < i && i < N - 1) {
            belt[i] = tempBelt[i-1];
            robotPos[i] = tempRobotPos[i-1];
        } else if (i == N - 1) {
            belt[i] = tempBelt[i-1];
            robotPos[i] = 0;
        }
        if(N <= i && i < N * 2) 
            belt[i] = tempBelt[i-1];
    }
}

int moveRobot() 
{
    int downPos = N - 1;
    int cnt = 0;

    for(int i = downPos; 0 <= i; i--) {
        if(robotPos[i] == 1) {
            if(i == downPos)
                robotPos[i] = 0;
            else {
                if(robotPos[i+1] == 1 || belt[i+1] == 0) continue;
                robotPos[i] = 0;
                robotPos[i+1] = 1;
                if(!--belt[i+1]) cnt++;
            }
        }
    }
    return cnt;
}

int uploadRobot() 
{
    if(belt[0] != 0) {
        robotPos[0] = 1;
        if(!--belt[0]) return 1;
    }
    return 0;
}

void solve() 
{
    int level = 0, cnt = 0;

    while(cnt < K) {
        rotateBelt();
        cnt += moveRobot();
        cnt += uploadRobot();
        level++;
    }

    cout << level << '\n';
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> N >> K;
    for(int i = 0; i < N * 2; i++) {
        cin >> n;
        belt.push_back(n);
    }
    robotPos.assign(N, 0);

    solve();

    return 0;
}