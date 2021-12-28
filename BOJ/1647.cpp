#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

struct Edge {
    int x, y, w;
    Edge(int x, int y, int w): x{x}, y{y}, w{w} {};
};


bool compareEdge(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int N, M, cnt = 0;
int parent[MAX+1];
vector<Edge> edges;

int getParent(int v) {
    if(parent[v] == v) return v;
    return parent[v] = getParent(parent[v]);
}

bool checkCycle(int x, int y) {
    int parentX = getParent(x);
    int parentY = getParent(y);

    return parentX == parentY;
}

void unionNode(int x, int y) {
    int parentX = getParent(x);
    int parentY = getParent(y);

    if(parentX < parentY) parent[parentY] = parentX; 
    else parent[parentX] = parentY; 
}


int main() {
    int x, y, w;
    vector<int> costs;
    cin >> N >> M;

    for(int i = 0; i <= N; i++) 
        parent[i] = i;

    for(int i = 0; i < M; i++) {
        cin >> x >> y >> w;
        edges.push_back(Edge(x, y, w));
    }

    sort(edges.begin(), edges.end(), compareEdge);

    for(int i = 0; i < edges.size(); i++) {
        x = edges[i].x;
        y = edges[i].y;
        w = edges[i].w;

        if(checkCycle(x,y)) continue;

        if(N-1 < ++cnt) break;
        unionNode(x, y);
        costs.push_back(w);
    }

    sort(costs.begin(), costs.end());

    int sum = 0;

    for(int i = 0; i < costs.size() - 1; i++)
        sum += costs[i];

    cout << sum << '\n';

    return 0;
}