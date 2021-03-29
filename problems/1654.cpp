#include <iostream>
using namespace std;

int K, N;
unsigned int list[10000];
unsigned int Left, Right, mid, mx = 0, num, ans;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> K >> N;
    for(int i = 0; i < K; i++) {
        cin >> list[i];
        mx = max(mx, list[i]);
    }

    Left = 1; Right = mx;
    ans = 0;
    while(Left <= Right)
    {
        num = 0;
        mid = (Left + Right) / 2;
        for(int i = 0; i < K; i++) 
            num += list[i] / mid;

        if(num < N) { // 목표 랜선수보다 적은 경우
            Right = mid -1;
        } else if(num >= N) { // 목표 랜선수보다 같거나 많은 경우
            Left = mid + 1;
            ans = max(mid, ans);
        }
    }

    cout << ans << '\n';
    
    return 0;
}