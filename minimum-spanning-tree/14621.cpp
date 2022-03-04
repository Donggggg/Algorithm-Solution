#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000
#define P pair<int,int>
using namespace std;

struct Node {
    int n;
    int w;
    int b;
};

struct cmp {
    bool operator()(Node &n1, Node &n2) {
        return n1.w > n2.w;
    }
};

int N, M;
char gender[MAX+1];
vector<vector<P>> graph;

bool check(bool* visits) {
    for(int i = 1; i <= N; i++)
        if(!visits[i]) return false;
    return true;
}

int getLovePath() {
    priority_queue<Node, vector<Node>, cmp> pq;
    bool visits[MAX+1] = {false, };
    int sum = 0;

    pq.push({1, 0, gender[1]});

    while(!pq.empty()) {
        int v = pq.top().n;
        int w = pq.top().w;
        int bg = pq.top().b;
        pq.pop();
        
        if(visits[v]) continue;
        sum += w;
        visits[v] = true;

        for(int i = 0; i < graph[v].size(); i++) {
            int nextV = graph[v][i].first;
            int nextW = graph[v][i].second;
            
            if(gender[nextV] == bg) continue;
            
            pq.push({nextV, nextW, gender[nextV]});
        }
    }

    if(check(visits)) return sum;

    return -1;
}

int main() {
    int u, v, d;

    cin >> N >> M;

    graph.push_back(vector<P>());
    for(int i = 0; i < N; i++) {
        cin >> gender[i+1];
        graph.push_back(vector<P>());
    }

    for(int i = 0; i < M; i++) {
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    cout << getLovePath() << '\n';

    return 0;
}