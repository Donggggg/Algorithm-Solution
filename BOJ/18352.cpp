#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NODE_NUM 300001

int N, M, K, X;
int x, y, cur;
vector<int> list[NODE_NUM];
int dis[NODE_NUM];
queue<int> q;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K >> X;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        list[x].push_back(y);
    }

    for(int i = 0; i < NODE_NUM; i++)
        dis[i] = 99999999;

    q.push(X);
    dis[X] = 0;

    while(!q.empty()) {
        cur = q.front(); q.pop();
        for(int i = 0; i < list[cur].size(); i++) {
            if(dis[list[cur][i]] > dis[cur] + 1) {
                dis[list[cur][i]] = dis[cur] + 1;
                q.push(list[cur][i]);
            }
        }
    }

    bool isVoidOneAnswer = true;
    for(int i = 0 ; i < NODE_NUM; i++)
        if(dis[i] == K) {
            cout << i << "\n";
            isVoidOneAnswer = false;
        }
    if(isVoidOneAnswer)
        cout << "-1" << "\n";

    return 0;
}