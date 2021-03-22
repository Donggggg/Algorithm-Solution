#include <iostream>
using namespace std;

int N;
long long M, list[100000], mx = 0;
long long low, high, mid, res, sum;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> list[i];
        mx = max(mx, list[i]);
    }

    low = 1; 
    high = res = mx * M;

    while(low <= high) {
        mid = (low + high) / 2;
        
        sum = 0;
        for(int i = 0; i < N; i++) {
            sum += mid / list[i];
        }
        
        if(M <= sum) {
            res = min(mid, res);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << res << '\n';
    
    return 0;
}