#include <iostream>
#include <algorithm>
using namespace std;

int N, S, arr[100000];
int s, e, cur, len = 100001;
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];

    s = e = cur = 0;
    while(e <= N) {
        if(cur < S || e <= s) {
            cur += arr[e++];
        } else if (cur >= S) {
            cur -= arr[s++];
            len = min(len, (e - s + 1));
        }
    }

    len > 100000 ? cout << 0 << '\n' : cout << len << '\n';
    return 0;
}