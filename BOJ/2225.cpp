#include <iostream>
#define MAX 200
#define MOD 1000000000
using namespace std;

int N, K;
int dp[MAX+1][MAX+1];

int main() {
    cin >> N >> K;

    for(int i = 0; i <= MAX; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= K; i++) {
        for(int j = 0; j <= N; j++) {
            int sum = 0;

            for(int k = 0; k <= j; k++) 
                sum = (sum + dp[i-1][k]) % MOD;
            
            dp[i][j] = sum;
        }
    }

    cout << dp[K][N] << '\n';

    return 0;
}