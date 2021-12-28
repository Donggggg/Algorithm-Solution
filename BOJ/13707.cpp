#include <iostream>
#define MAX 5000
#define MOD 1000000000
using namespace std;

int N, K;
int dp[MAX+1][MAX+1];

int main() {
    cin >> N >> K;

    for(int i = 0; i <= MAX; i++) {
        dp[1][i] = 1; 
        dp[i][0] = 1;
    }

    for(int i = 2; i <= K; i++) 
        for(int j = 1; j <= N; j++) 
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;

    cout << dp[K][N] << '\n';

    return 0;
}