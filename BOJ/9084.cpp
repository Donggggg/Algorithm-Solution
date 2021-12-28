#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10000
using namespace std;

int main() {
    int T, N, target;
    int dp[MAX+1] = {0, };
    vector<int> coins;

    int n;
    cin >> T;

    while(T--) {
        cin >> N;
        coins.clear();
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < N; i++) {
            cin >> n;
            coins.push_back(n);
        }
        cin >> target;

        for(int i = 0; i < coins.size(); i++)
            for(int j = coins[i]; j <= target; j++) 
                dp[j] += dp[j - coins[i]];

        cout << dp[target] << '\n';

    }

    return 0;
}