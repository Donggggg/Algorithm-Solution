#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];
int dp[1000][2];
int list[1000];
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < 1000; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i][0] = max(dp[i][0], dp[j][0]+1);
            }
        }
    }
    for(int i = N-2; 0 <= i; i--) {
        for(int j = N-1; i <= j; j--) {
            if(arr[i] > arr[j]) {
                dp[i][1] = max(dp[i][1], dp[j][1]+1);
            }
        }
    }
    for(int i = 0; i < N; i++)
        list[i] = dp[i][0] + dp[i][1] - 1;

    sort(list, list+N);

    cout << list[N-1] << '\n';
    return 0;
}