#include <iostream>
#define MAX 64
using namespace std;

int main()
{
    int T, n;
    long long dp[MAX + 1][10] = {0, };
    long long ans[MAX + 1]= {0, };

    cin >> T; 

    for(int i = 0; i < 10; i++) {
        dp[1][i] = 1;
        ans[1] += 1;
    }

    for(int i = 2; i <= MAX; i++)
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] += dp[i-1][k];                
            }
            ans[i] += dp[i][j];
        }

    while(T--) {
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}