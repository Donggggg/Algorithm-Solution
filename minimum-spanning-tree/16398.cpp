#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000
#define P pair<int,int>
using namespace std;

int N;
int graph[MAX][MAX];

struct compare {
    bool operator()(P &p1, P &p2) {
        return p1.second > p2.second;
    }
};


long long  findMinimumPrice() {
    priority_queue<P, vector<P>, compare> pq;
    bool visits[MAX] = {false, };
    long long sum = 0;

    pq.push({0, 0});

    while(!pq.empty()) {
        int v = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if (visits[v]) continue;

        visits[v] = true;
        sum += w;

        for(int i = 0 ; i < N; i++) {
            if(i == v || visits[i]) continue;
            pq.push({i, graph[v][i]});
        }
    }

    return sum;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    cout << findMinimumPrice() << '\n';

    return 0;
}