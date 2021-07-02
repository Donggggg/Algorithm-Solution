#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int arr[1000];
int dp[1000] = {1,};

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    for(int i = 0; i < N; i++)
    dp[i] = 1;


    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

for(int i = 0 ; i < N; i++)
    sort(dp, dp+N);

    cout << dp[N-1] << '\n';
    return 0;
}