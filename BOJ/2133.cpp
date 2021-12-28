#include <iostream>
using namespace std;

int main() {
    int N;
    int dp[31] = {0, };

    cin >> N;

    if(N % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    dp[2] = 3;

    for(int i = 4; i <= N; i+= 2) {
        dp[i] += 3 * dp[i - 2];

        for(int j = 4; j <= i; j+= 2) 
            dp[i] += 2 * dp[i-j];
            
        dp[i] += 2;

    }

    cout << dp[N] << '\n';

    return 0;
}