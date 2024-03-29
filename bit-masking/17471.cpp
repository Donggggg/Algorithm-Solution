#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10
#define OVER 1000
#define BIN_MAX 1024
using namespace std;

int N, w[MAX+1], ans = OVER;
bool visits[BIN_MAX];
vector<vector<int>> graph;

int getDiff(int bin) {
    int tb = bin;
    int i = 1, cnt = 1, sum[2], lidx;
    vector<int> list[2];
    queue<int> q;

    while(bin) {
        list[bin % 2].push_back(i++);
        bin >>= 1;
    }

    lidx = list[0].size() + list[1].size() + 1;

    if(lidx <= N) {
        for(i = lidx; i <= N; i++)
            list[0].push_back(i);
    }

    if(list[0].size() == 0 || list[1].size() == 0)
        return OVER;

    bool v[MAX + 1] = {false, };
    v[list[0][0]] = true;
    q.push(list[0][0]);
    sum[0] = w[list[0][0]];

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            if(v[next] || find(list[1].begin(), list[1].end(), next) != list[1].end())
                continue;

            v[next] = true;
            q.push(next);
            sum[0] += w[next];
            cnt++;
        }
    }

    if(cnt != list[0].size())
        return OVER;
    
    cnt = 1;
    v[list[1][0]] = true;
    q.push(list[1][0]);
    sum[1] = w[list[1][0]];

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            if(v[next] || find(list[0].begin(), list[0].end(), next) != list[0].end())
                continue;

            v[next] = true;
            q.push(next);
            sum[1] += w[next];
            cnt++;
        }
    }

    if(cnt != list[1].size())
        return OVER;

    return abs(sum[0] - sum[1]);
}

void getMinAns(int idx, int bin) {
    if(!visits[bin]) {
        visits[bin] = true;
        int diff = getDiff(bin);
        if(diff < ans) ans = diff;
    }

    for(int i = idx+1; i < N; i++) {
        int nextBin = bin + pow(2, i);
        if(visits[nextBin]) continue;
        getMinAns(i, nextBin);
    }
}

void solve() {
    for(int i = 0; i < N; i++) 
        getMinAns(i, pow(2, i));

    if(ans != OVER) cout << ans << '\n';
    else cout << -1 << '\n';
}

int main() {
    int n, x;
    cin >> N;
    graph.assign(N+1, vector<int>());

    for(int i = 0; i < N; i++)
        cin >> w[i+1];

    for(int i = 0; i < N; i++) {
        cin >> n;
        while(n--) {
            cin >> x;
            graph[i+1].push_back(x);
        }
    }
    
    solve();

    return 0;
}