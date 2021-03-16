#include <iostream>
using namespace std;

int N, arr[10000], ans = 0;
int dp[1001][1001] = {0, };

int getMaxValue(int i, int j)
{
    int mx = 0;
    for(int a = 1; a <= j; a++) 
        mx = max(dp[i-j][a], mx);
    
    return mx;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i+1][i+1] = arr[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            dp[i][j] = dp[j][j] + getMaxValue(i, j);
        }
    }

    for(int i = 0; i <= N; i++)
        ans = max(ans, dp[N][i]);

    cout << ans << '\n';

    return 0;
}