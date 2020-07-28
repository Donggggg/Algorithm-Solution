#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MOD 1000000000

int main()
{
	int n;
	long long dp[101][10] = { 0, };
	int ans = 0;

	cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][1] += dp[i - 1][j];
			else if (j == 9)
				dp[i][8] += dp[i - 1][j];
			else {
				dp[i][j - 1] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
				dp[i][j + 1] = (dp[i - 1][j] + dp[i][j + 1]) % MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		ans = (dp[n][i] + ans) % MOD;

	printf("%d\n", ans);
	
}