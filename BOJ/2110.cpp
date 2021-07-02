#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> list;

bool isOver(int mid)
{
    int cnt = 0, cur = 0;

    for(int i = 1; i < list.size(); i++) 
    {
        if(list[i] - list[cur] >= mid) {
            cnt++;
            cur = i;
        }

        if(cnt == C-1)
            return true;
    }

    return false;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, left, right, mid, ans;
    ans = 0;

    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        cin >> n;
        list.push_back(n);
    }

    sort(list.begin(), list.end()); // O(nlogn)

    left = 1;
    right = *(list.end()-1);

    // O(nlogn)
    while(left <= right)
    {
        mid = (left + right) / 2;

        // O(n)
        if(isOver(mid)) {
            left = mid + 1;
            ans = max(ans, mid);
        } else {
            right = mid - 1;
        }

    }

    cout << ans << "\n";
    
    return 0;
}