#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[201];
int dp[201];

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) 
        cin >> arr[i];
    for (int i = 0; i <= 200; i++)
        dp[i] = 1;
    
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    sort(dp, dp+N+1);

    cout << N - dp[N] << '\n';

    return 0;
}