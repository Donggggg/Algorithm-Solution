#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_NODE 20000
#define INF 3000000
using namespace std;

int V, E, K;
vector<pair<int,int>> graph[MAX_NODE+1];
int d[MAX_NODE+1];

void dijkstra(int K)
{
    queue<int> q;
    q.push(K);

    while(!q.empty())
    {
        printf("hello");
        int cur = q.front(); q.pop();
        
        for(int i = 0; i < graph[cur].size(); i++) {
            int dest = graph[cur][i].first;
            int w = graph[cur][i].second;
            if(d[dest] < d[cur] + w) continue;
            d[dest] = d[cur] + w;
            q.push(dest);
        }
    }
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int u, v, w;
    cin >> V >> E;
    cin >> K;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
    }
    fill(d, d+V+1, INF);
    d[K] = 0;
    dijkstra(K);

    for(int i = 1; i <= V; i++) 
        d[i] == INF ? cout << "INF" << '\n' : cout << d[i] << '\n';
    
    return 0;
}