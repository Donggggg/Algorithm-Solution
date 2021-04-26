#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[301];
long long dp[301] = {0,};
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[1] = arr[1];
    dp[2] = arr[2] + arr[1];

    for(int i = 3; i <= N; i++) {
        dp[i] = arr[i] + max(arr[i - 1] + dp[i - 3], dp[i - 2]);
    }
    cout << dp[N] << '\n';
    return 0;
}