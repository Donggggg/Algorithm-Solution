#include <iostream>
#include <algorithm>
using namespace std;

int T, N, numOne;
int list[10] = {0,0,1,7,4,2,0,8,10};
long long dp[101]= {0,};

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> T;

    while(T--) {
        cin >> N;

        for (int i = 2; i < 10; i++)
            dp[i] = list[i];
        dp[6] = 6;

        for(int i = 9; i <= N; i++) {
            dp[i] = dp[i - 2] * 10 + dp[2];
            for(int j = 3; j < 8; j++) {
                dp[i] = min(dp[i], dp[i-j] * 10 + list[j]);
            }
        }
        cout << dp[N] << ' ';

        if (N % 2) {
            numOne = (N-3) / 2;
            cout << "7";
        } else {
            numOne = N / 2;
        }
        for(int i = 0 ; i < numOne; i++)
            cout << "1";

        cout << "\n";
    }
    return 0;
}