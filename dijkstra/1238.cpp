#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int,int>
#define MAX 1000
#define INF 100001
using namespace std;

int N, M, X;
vector<vector<P>> graph;
vector<int> answers;

struct cmp {
    bool operator()(P &p1, P &p2) {
        return p1.second > p2.second;
    }
};

int getDistance(int start, int end) {
    priority_queue<P, vector<P>, cmp> pq;
    int dist[MAX+1];

    for(int i = 0; i <= MAX; i++)
        dist[i] = INF;

    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty()) {
        int cur = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if(dist[cur] < w) continue;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nw = graph[cur][i].second;

            if(w + nw < dist[next]) {
                dist[next] = w + nw;
                pq.push({next, dist[next]});
            }
        }
    }

    return dist[end];
}

int main() {
    int x, y, w;

    cin >> N >> M >> X;

    graph.assign(MAX+1, vector<P>());
    answers.assign(N+1, 0);

    for(int i = 0; i < M; i++) {
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }

    for(int i = 1; i <= N; i++) 
         answers[i] = getDistance(i, X) + getDistance(X, i);

    cout << *max_element(answers.begin(), answers.end()) << '\n';

    return 0;
}