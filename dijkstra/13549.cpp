#include <iostream>
#include <vector>
#include <queue>
#define P pair<int,int>
#define MAX 100000
using namespace std;

struct cmp {
    bool operator()(P &p1, P &p2) {
        return p1.second > p2.second;
    }
};

int N, K;

int getFastestTime(int start) {
    priority_queue<P, vector<P>, cmp> pq;
    vector<int> times;
    int d[2] = {1, -1};
    times.assign(MAX+1, MAX);

    pq.push({start, 0});
    times[start] = 0;

    while(!pq.empty()) {
        int cur = pq.top().first;
        int t = pq.top().second;
        pq.pop();

        if(times[cur] < t) continue;
        if(cur == K) break;

        if(cur * 2 <= MAX && t < times[cur * 2]) {
            times[cur*2] = t;
            pq.push({cur*2, t});
        }

        for(int i = 0; i < 2; i++) {
            int next = cur + d[i];

            if(next < 0 || MAX < next) 
                continue;

            if(t + 1 < times[next]) {
                times[next] = t + 1;
                pq.push({next, t + 1});
            }
        }
    }

    return times[K];

}

int main() {
    cin >> N >> K;

    cout << getFastestTime(N) << '\n';

    return 0;
}