#include <iostream>
#include <vector>
#include <queue>
#define P pair<int,int>
#define MAX 1000
using namespace std;

int N, M;
vector<vector<P>> graph;

struct cmp {
    bool operator()(P &p1, P &p2) {
        return p1.second > p2.second;
    }
};

int findMinimumNetwork() {
    priority_queue<P, vector<P>, cmp> q;
    bool visits[MAX+1] = {false, };
    int sum = 0;

    q.push({1, 0});

    while(!q.empty()) {
        int cur = q.top().first;
        int w = q.top().second;
        q.pop();

        if(visits[cur]) continue;
        visits[cur]  = true;
        sum += w;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextW = graph[cur][i].second;

            q.push({next, nextW});
        }
    }

    return sum;
}

int main() {
    int x, y, w;

    cin >> N;
    cin >> M;

    for(int i = 0; i <= N; i++)
        graph.push_back(vector<P>());

    for(int i = 0; i < M; i++) {
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    cout << findMinimumNetwork() << '\n';

    return 0;
}