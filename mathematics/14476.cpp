#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> list, leftSide, rightSide;

int getGCD(int x, int y) {
    if(x % y == 0)
        return y;
    else 
        return getGCD(y, x % y);
}

int main() {
    int x, gcd, ans = -1, idx;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x;
        list.push_back(x);
    }

    leftSide.push_back(list[0]);
    for(int i = 1; i < N; i++)
        leftSide.push_back(getGCD(leftSide.back(), list[i]));

    rightSide.push_back(list[N-1]);
    for(int i = N-2; 0 <= i; i--)
        rightSide.push_back(getGCD(rightSide.back(), list[i]));    

    for(int i = 0; i < N; i++) {
        int j = N - 1 - i;

        if(i == 0)
            gcd = rightSide[j - 1];
        else if(i == N - 1)
            gcd = leftSide[i - 1];
        else gcd = getGCD(leftSide[i - 1], rightSide[j - 1]);

        if(ans < gcd && list[i] % gcd != 0) {
            ans = gcd;
            idx = i;
        }
    }

    if(ans > 0) 
        cout << ans << ' ' << list[idx] << '\n';
    else 
        cout << ans << '\n';

    return 0;
}