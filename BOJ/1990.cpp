/*
1. 에라토스테네스의 체를 활용해 MAX 범위까지의 소수를 추린다.
2. 탐색할 범위(a ~ b)까지 1씩 증가하며 소수인 펠린드롬을 판단해 출력한다.

1. 탐색할 범위에서 펠린드롬인 숫자를 찾는다.
2. 찾은 숫자가 소수이면 출력한다.

0. b가 10,000,000 초과면 10,000,000으로 고정한다. (10,000,000 이상의 펠린드롬인 소수가 없다고하네 ;;;.)
1. 탐색할 범위에서 펠린드롬인 숫자를 찾는다.
2. 찾은 숫자가 소수이면 출력한다.
*/

#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#define MAX 100000000
#define PMAX 10000000
using namespace std;

bool list[MAX + 1] = {false, };

int main()
{
    int a, b;

    cin >> a >> b;
    if(b > PMAX) b = PMAX;

    for (int i = a; i <= b; i++) {
        string str = to_string(i);
        string rstr = str;
        reverse(rstr.begin(), rstr.end());
        if(str == rstr) {
            bool isValid = true;
            for(int j = 2; j <= sqrt(i); j++)
                if(i % j == 0) {
                    isValid = false;
                    break;
                }
            if(isValid) cout << i << '\n';
        }
    }

    cout << -1 << '\n';

    return 0;
}