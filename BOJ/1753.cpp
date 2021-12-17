#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#define P pair<int,int>
#define MAX 20001
#define INF 2000001
using namespace std;


int V, E, T;
vector<set<P>> graph;

struct cmp {
    bool operator()(P &p1, P &p2) {
        return p1.second > p2.second;
    }
};

vector<int> dijsktra(int sVertex) {
    set<P>::iterator iter;
    priority_queue<P, vector<P>, cmp> pq;
    vector<int> dist(V+1, INF);
    vector<bool> visits(V+1, false);

    dist[sVertex] = 0;
    pq.push(make_pair(sVertex, 0));

    while(!pq.empty()) {
        int v = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if(visits[v]) continue;
        visits[v] = true;

        
        for(iter = graph[v].begin(); iter != graph[v].end(); iter++) {
            int nv = (*iter).first;
            int nw = (*iter).second;

            if(dist[nv] > dist[v] + nw) {
                dist[nv] = dist[v] + nw;
                pq.push(make_pair(nv, dist[nv]));
            }
        }
    }

    return dist;
}

int main() {
    int x, y, w;
    vector<int> answer;

    cin >> V >> E;
    cin >> T;

    for(int i = 0; i <= V; i++)
        graph.push_back(set<P>());

    for(int i = 0; i < E; i++) {
        cin >> x >> y >> w;
        graph[x].insert(make_pair(y, w));
    }

    answer = dijsktra(T);

    for(int i = 1; i <= V; i++) {
        if(answer[i] == INF) cout << "INF" << '\n';
        else cout << answer[i] << '\n';
    }

    return 0;
}