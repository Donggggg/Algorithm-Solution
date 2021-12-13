#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int R, C;
vector<string> list;

bool check(int row) {
  set<string> s;

  for(int i = 0; i < C; i++) {
        string str;

        for(int j = row; j < R; j++) 
            str += list[j][i];
        
        if(s.find(str) != s.end()) return false;
        s.insert(str);
    }

    return true;
}

int main()
{
    int start, end, mid, ans = 0;
    string str;
    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        cin >> str;
        list.push_back(str);
    }

    start = 0;
    end = R - 1;

    while (start <= end) {
        mid = (start + end) / 2;

        if(check(mid)) {
            start = mid + 1;
            if(ans < mid) ans = mid;
        } else 
            end = mid - 1;
    }

    cout << ans << '\n';

    return 0;
}