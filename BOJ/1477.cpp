#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L;
vector<int> rests;

int buildRest(int value) {
    int cnt = M;
    
    for(int i = 0; i < rests.size() - 1; i++) {
        int diff = rests[i+1] - rests[i];

        cnt -= diff / value;

        if(diff % value == 0) cnt++;
    }
    
    return cnt;
}

int findMininum() {
    int start, end, mid, ans = L;
    start = 1;
    end = L;

    while(start <= end) {
        mid = (start + end) / 2;

        int cnt = buildRest(mid);

        if(cnt < 0) start = mid + 1;
        else {
            ans = min(ans, mid);
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;

    cin >> N >> M >> L;

    rests.push_back(0);

    for(int i = 0; i < N; i++) {
        cin >> n;
        rests.push_back(n);
    }

    rests.push_back(L);

    sort(rests.begin(), rests.end());

    cout << findMininum() << '\n';

    return 0;
}