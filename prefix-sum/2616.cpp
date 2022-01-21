#include <iostream>
#include <vector>
#include <set>
#define MAX 50000
#define MAX_TRAIN 3
using namespace std;

int N, M;
int dp[MAX_TRAIN+1][MAX+1];
vector<int> list, slist;

int main() {
    int x, sum;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x;
        list.push_back(x);
    }
    cin >> M;

    slist.push_back(0);
    for(int i = 0; i < N; i++) {
        sum = list[i] + slist[i];
        slist.push_back(sum);
    }

    for(int i = 1; i <= MAX_TRAIN; i++) 
        for(int j = i * M; j <= N; j++) 
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-M] + (slist[j] - slist[j-M]));
        
    cout << dp[3][N] << '\n';

    return 0;
}