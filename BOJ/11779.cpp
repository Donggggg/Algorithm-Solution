#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define P pair<int,int>
#define INF 100000001
#define MAX 1000
using namespace std;

int n, m, s, e;
int dist[MAX+1], path[MAX+1];
vector<vector<P>> graph;

struct cmp {
    bool operator()(P &p1, P &p2) {
        return p1.second > p2.second;
    }
};

void dijkstra(int start) {
    priority_queue<P, vector<P>, cmp> pq;

    pq.push({start, 0});
    dist[start] = 0;

    while(!pq.empty()) {
        int cur = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        if(dist[cur] < d) continue;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nd = graph[cur][i].second;

            if(d + nd < dist[next]) {
                dist[next] = d + nd;
                path[next] = cur;
                pq.push({next, dist[next]});
            }
        }
    }
}

void printPath(int end) {
    int cnt = 0, cur;
    vector<int> routes;

    cur = end;

    while(1) {
        if(cur == 0) break;

        cnt++;
        routes.push_back(cur);
        cur = path[cur];
    }

    cout << cnt << '\n';

    for(int i = routes.size() - 1; 0 <= i; i--)  
        cout << routes[i] << ' ';

    cout << '\n';
}

int main() {
    int x, y, w;
    cin >> n;
    cin >> m;
    
    for(int i = 0; i <= n; i++) {
        graph.push_back(vector<P>());
        dist[i] = INF;
    }

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        graph[x].push_back({y,w});
    }

    cin >> s >> e;

    dijkstra(s);

    cout << dist[e] << '\n';

    printPath(e);

    return 0;
}