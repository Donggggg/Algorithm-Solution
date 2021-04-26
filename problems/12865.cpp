#include <iostream>
using namespace std;

int N, K;
int bag[101][2];
long long dp[102][100003];
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> bag[i][0] >> bag[i][1];

    for(int i = 1; i <= N; i++) {
        int w = bag[i][0], v = bag[i][1];
        for(int j = 0; j <= K; j++) {
            if (j < w)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], v + dp[i-1][j - w]);
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}