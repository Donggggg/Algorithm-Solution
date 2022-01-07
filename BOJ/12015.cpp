#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000001
using namespace std;

int main() {
    int N, x;
    vector<int> arr, list, idx, ans;
    idx.assign(1000001, 0);

    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> x;
        arr.push_back(x);
    }

    list.push_back(-MAX);

    for(int i = 0; i < N; i++) {
        if(arr[i] <= list.back()) {
            int index = lower_bound(list.begin(), list.end(), arr[i]) - list.begin();
            list[index] = arr[i];
            idx[i] = index;
        }
        else {
            list.push_back(arr[i]);
            idx[i] = list.size() - 1;
        }
    }

    int cur = list.size() - 1;

    cout << cur << '\n';

    for(int i = arr.size() - 1; 0 <= i; i--) {
        if(cur == idx[i]) {
            ans.push_back(arr[i]);
            cur--;
        }
    }

    for(int i = ans.size()-1; 0 <= i; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}