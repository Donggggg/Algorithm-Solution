#include <iostream>
#include <algorithm>
using namespace std;

int n;
int bottle[10001];
long long dp[10001];
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> bottle[i];
    
    dp[0] = 0;
    dp[1] = bottle[1];
    dp[2] = bottle[1] + bottle[2];

    for(int i = 3; i <= n; i++) {
        dp[i] = bottle[i] + max(bottle[i-1]+dp[i-3], dp[i-2]);
        dp[i] = max(dp[i], dp[i-1]);
    }

    // sort(dp, dp+n+1);
    cout << dp[n] << '\n';
    return 0;
}