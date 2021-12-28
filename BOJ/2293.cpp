#include <iostream>
#define MAX 100000
using namespace std;

int n, k;
int coins[MAX+1];
int dp[MAX+1];

int main() {
    cin >> n >> k;

    dp[0] = 1;

    for(int i = 0; i < n; i++) 
        cin >> coins[i];

    for(int i = 0; i < n; i++)
        for(int j = coins[i]; j <= k; j++) 
            dp[j] += dp[j - coins[i]];
        

    cout << dp[k] << '\n';

    return 0;
}