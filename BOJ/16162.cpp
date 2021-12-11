#include <iostream>
#include <vector>
#define MAX 200001
using namespace std;

int main()
{
    int N, A, D, num, cur, cnt = 0;
    bool table[MAX] = {false, };

    cin >> N >> A >> D;
    cur = A;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if(num == cur) {
            cnt++;
            cur += D;
        }
    }
    
    cout << cnt << '\n';

    return 0;
}