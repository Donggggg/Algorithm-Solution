#include <iostream>
#include <vector>
#include <queue>
#define MAX 10000
using namespace std;

int V, E;
vector<vector<pair<int,int>>> graph;
bool visits[MAX+1];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
    int v1, v2, w, cnt = 0, v;
    long long sum = 0;

    cin >> V >> E;

    for(int i = 0; i <= V; i++)
        graph.push_back(vector<pair<int,int>>());

    for(int i = 0; i < E; i++){
        cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2,w));
        graph[v2].push_back(make_pair(v1,w));
    }

    pq.push(make_pair(0, 1));

    while(!pq.empty()) {
        v =  pq.top().second; 
        w = pq.top().first;
        pq.pop();
        if(visits[v]) continue;
        visits[v] = true;
        sum += w;

        for(int n = 0; n < graph[v].size(); n++) {
            if(!visits[graph[v][n].first])
                pq.push(make_pair(graph[v][n].second, graph[v][n].first));
        }
    }

    cout << sum << '\n';

    return 0;
}