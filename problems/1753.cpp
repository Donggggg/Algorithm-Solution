#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define NODE_NUM 20001
#define MAX 1000000

int V, E, K;
int x, y, w;
vector<pair<int,int>> nodes[NODE_NUM];
int dist[NODE_NUM];
queue<int> q;

bool isExist(int x, int y, int w)
{
    for(int i = 0; nodes[x].size(); i++) 
        if(nodes[x][i].first == y)
            if(nodes[x][i].second > w) {
                nodes[x][i].second = w;
                return true;
            }
    return false;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> V >> E;
    cin >> K;
    for(int i = 0; i < E; i++) {
        cin >> x >> y >> w;
        if(!isExist(x,y,w)) 
            nodes[x].push_back(make_pair(y,w));
    }
            printf("d\n");

    for(int i = 0; i <= NODE_NUM; i++) 
        dist[i] = MAX;
    
    dist[K] = 0;
    q.push(K);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < nodes[cur].size(); i++) {
            int pre = nodes[cur][i].first, weight = nodes[cur][i].second;
            if(dist[pre] > dist[cur] + weight) {
                dist[pre] = dist[cur] + weight;
                q.push(pre);
            }
        }
    }

    for(int i = 1 ; i <= V; i++) {
        if(dist[i] == MAX)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}