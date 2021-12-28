#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define P pair<int, int>
#define MAX 100000
using namespace std;

struct cmp {
    bool operator()(P &p1, P &p2) {
        return p1.second > p2.second;
    };
};

int N;
vector<P> planetX, planetY, planetZ;
vector<P> planets[MAX];

long long findMinimumCost() {
    priority_queue<P, vector<P>, cmp> pq;
    bool visits[MAX] = {false, };
    long long sum = 0;

    pq.push({0, 0});
    
    while(!pq.empty()) {
        int n = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if(visits[n]) continue;
        visits[n] = true;
        sum += dist;

        for(int i = 0; i < planets[n].size(); i++) {
            int next = planets[n][i].first;
            int newDist = planets[n][i].second;
            if(next == n || visits[next]) continue;
            
            pq.push({next, newDist});
        } 
    }

    return sum;
}

int main() {
    int x, y, z;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x >> y >> z;
        planetX.push_back({x, i});
        planetY.push_back({y, i});
        planetZ.push_back({z, i});
    }

    sort(planetX.begin(), planetX.end());
    sort(planetY.begin(), planetY.end());
    sort(planetZ.begin(), planetZ.end());

    for(int i = 0; i < N - 1; i++) {
        // int minDist = min(min(planetX[i+1].first - planetX[i].first, planetY[i+1].first - planetY[i].first), planetZ[i+1].first - planetZ[i].first);
        planets[planetX[i+1].second].push_back({planetX[i].second, planetX[i+1].first - planetX[i].first});
        planets[planetX[i].second].push_back({planetX[i+1].second, planetX[i+1].first - planetX[i].first});
        planets[planetY[i+1].second].push_back({planetY[i].second, planetY[i+1].first - planetY[i].first});
        planets[planetY[i].second].push_back({planetY[i+1].second, planetY[i+1].first - planetY[i].first});
        planets[planetZ[i+1].second].push_back({planetZ[i].second, planetZ[i+1].first - planetZ[i].first});
        planets[planetZ[i].second].push_back({planetZ[i+1].second, planetZ[i+1].first - planetZ[i].first});
    }

    cout << findMinimumCost() << '\n';

    return 0;
}