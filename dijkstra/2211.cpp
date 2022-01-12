#include <iostream>
#include <queue>
#include <vector>
#define P pair<int,int>
#define INF 10000
#define MAX 1000
using namespace std;


struct cmp {
    bool operator ()(P &p1, P &p2) {
        return p1.second > p2.second;
    }
};

int N, M;
vector<vector<P>> graph;
vector<int> recoveries;

void getRecoveries() {
    priority_queue<P, vector<P>, cmp> pq;
    vector<int> dist;

    dist.assign(MAX+1, INF);
    recoveries.assign(MAX+1, 0);
    dist[1] = 0;
    pq.push({1, 0});

    while(!pq.empty()) {
        int cur = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if(dist[cur] < w) continue;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nw = graph[cur][i].second + w;

            if(nw < dist[next]) {
                dist[next] = nw;
                recoveries[next] = cur;
                pq.push({next, nw});
            }
        }
    }
}

int main() {
    int x, y, w;
    cin >> N >> M;

    graph.assign(N+1, vector<P>());

    for(int i = 0; i < M; i++) {
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    getRecoveries();

    cout << N - 1 << '\n';
    for(int i = 2; i <= N; i++)
        cout << i << ' ' << recoveries[i] << '\n';

    return 0;
}