#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 1000

int S, number, clip, level, ans;
int visit[MAX+1][MAX+1] = {0, };
queue<pair<int,int>> q;
pair<int,int> cur;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> S;
    
    q.push(make_pair(1,0));

    while(!q.empty()) {
        cur = q.front(); q.pop();
        number = cur.first; clip = cur.second;
        level = visit[number][clip];

        if(number == S) {
            ans = level; break;
        }

        if(visit[number][number] == 0) { // 복사
            cur.first = number;
            cur.second = number;
            visit[cur.first][cur.second] = level + 1;
            q.push(cur);
        }
        if(number+clip <= MAX && clip != 0 && visit[number+clip][clip] == 0) { // 붙여넣기
            cur.first = number + clip;
            cur.second = clip;
            visit[cur.first][cur.second] = level + 1;
            q.push(cur);
        }
        if(number > 0 && visit[number-1][clip] == 0) { // 삭제
            cur.first = number -1;
            cur.second = clip;       
            visit[cur.first][cur.second] = level +1;
            q.push(cur);
        } 
    }

    cout << ans << "\n";

    return 0;
}