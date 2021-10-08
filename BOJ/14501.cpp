#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int> > arr;
int dp[15] = {0, };

int getBeforeMax(int day)
{
    int maxEarn = 0;
    for(int i = 0; i < day; i++) 
        if(arr[i].first + i + 1 <= day)
            maxEarn = max(maxEarn, dp[i]);
    return maxEarn;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int x, y, N, answer = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        arr.push_back(make_pair(x,y));
    }

    for(int i = 0; i < N; i++) {
        int day = i + 1, earn = 0;
        if (arr[i].first + day - 1 <= N) earn = arr[i].second;
        int maxEarn = getBeforeMax(day);
        dp[i] = earn + maxEarn;
        answer = max(dp[i], answer);
    }

    cout << answer << '\n';

    return 0;
}