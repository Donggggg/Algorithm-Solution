#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
#define MAX 800
#define INF 200000001
using namespace std;

int N, E;
vector<vector<P>> graph;

long long dijkstra(int start, int end) {
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<long long> dis(MAX+1, INF);

    if(start == end) return 0;
    
    dis[start] = 0;
    pq.push(P(start,0));

    while(!pq.empty()) {
        int v = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[v].size(); i++) {
            int next = graph[v][i].first;
            int w = graph[v][i].second;

            if(dis[next] > w + dis[v]) {
                dis[next] = w + dis[v];
                pq.push(P(next, w));
            }
        }
    }
    return dis[end];
}

int main() {
    int v1, v2, w, m1, m2;
    long long top[5] = {0, };

    cin >> N >> E;

    for(int i = 0; i <= N; i++)
        graph.push_back(vector<P>());

    for(int i = 0; i < E; i++) {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2, w));
        graph[v2].push_back(make_pair(v1, w));
    }

    cin >> m1 >> m2;

    top[0] = dijkstra(1, m1);
    top[1] = dijkstra(1, m2);
    top[2] = dijkstra(m1, m2);
    top[3] = dijkstra(m1, N);
    top[4] = dijkstra(m2, N);

    long long answer = min(top[0] + top[2] + top[4], top[1] + top[2] + top[3]);

    answer = (answer == 0 || INF <= answer) ? -1 : answer;
    
    cout << answer << '\n';

    return 0;
}