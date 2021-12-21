#include <iostream>
#include <memory.h>
#define MAX_MRB_NUM 5
#define MAX_MRB_CNT 10
using namespace std;

int N;
int m[MAX_MRB_NUM+1];
long long dp[MAX_MRB_CNT+1][MAX_MRB_CNT+1][MAX_MRB_CNT+1][MAX_MRB_CNT+1][MAX_MRB_CNT+1][MAX_MRB_NUM+1][MAX_MRB_NUM+1];

long long calcCase(int pre, int cur) {
    long long now = dp[m[1]][m[2]][m[3]][m[4]][m[5]][pre][cur];

    if(now != -1) return now;
    else if(m[1] + m[2] + m[3] + m[4] + m[5] == 0) return 1;
    else {
        long long sum = 0;

        for(int i = 1; i <= N; i++) {
            if(m[i] == 0 || pre == i || cur == i) continue;
            m[i]--;
            dp[m[1]][m[2]][m[3]][m[4]][m[5]][cur][i] = calcCase(cur, i);
            sum += dp[m[1]][m[2]][m[3]][m[4]][m[5]][cur][i];
            m[i]++;
        }

        dp[m[1]][m[2]][m[3]][m[4]][m[5]][pre][cur] = sum;
        
        return sum;
    }
}

int main() {
    long long answer = 0;
    memset(dp, -1, sizeof(dp));

    cin >> N;    
    
    for(int i = 1; i <= N; i++)
        cin >> m[i];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;

            m[i]--;
            m[j]--;
            answer += calcCase(i, j);
            m[i]++;
            m[j]++;
        }
    
    cout << answer << '\n';

    return 0;
}