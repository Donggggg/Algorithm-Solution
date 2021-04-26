#include <iostream>
using namespace std;

int  N;
long long dp[31][31] = {0,};

long long pill(int W, int H) 
{
    if(W < 0 || H < 0) return 0;
    if(dp[W][H] != 0) return dp[W][H];
    if(W== 0 && H == 0) return 1;
    
    long long cnt = 0;
    cnt = pill(W-1, H+1) + pill(W, H-1);

    return dp[W][H] = cnt;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    pill(30, 0);

    while (1) 
    {
        cin >> N;
        if(N == 0)
            break;
        cout << dp[N][0] << '\n';
    }
    return 0;
}