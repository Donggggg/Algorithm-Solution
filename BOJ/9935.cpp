#include <iostream>
#include <deque>
using namespace std;

deque<char> dq;
string str, bomb, ans;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> str;
    cin >> bomb;

    for(int i = 0; i < str.length(); i++) { // 한 글자씩 deque에 삽입
        dq.push_back(str[i]);

        if(dq.back() == bomb[bomb.length()-1]) { //현재 들어온 글자가 폭탄의 마지막 글자와 같은 경우
            int idx, isExplode;
            isExplode=1;
            // 폭발하는지 안하는지 검사
            for(int s = dq.size()-1, idx = bomb.length()-1; 0 <= idx && 0 <= s; s--, idx--) {
                if(dq[s] != bomb[idx]) { // 한 글자라도 다르면 폭발 안함
                    isExplode = 0;
                    break;
                }
            }

            if(!isExplode || dq.size() < bomb.length()) // 폭발하지 않으면 다음 문자 탐색
                continue;

            for(int s = 0; s < bomb.length(); s++) // 폭발한 만큼 deque에서 제거
                dq.pop_back();
        }
    }

    // 최종 문자열 dequq에서 string으로 옮김
    ans.resize(dq.size());
    for(int i = 0; i < dq.size(); i++) {
        ans[i] = dq[i];
    }
    if(dq.size() == 0)
        ans = "FRULA";

    cout << ans << '\n';

    return 0;
}