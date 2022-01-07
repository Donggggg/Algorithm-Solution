#include <iostream>
#include <vector>
#include <queue>
#define P pair<int,int>
#define MAX 10000
#define INF 1000000000
using namespace std;

int N, M;
vector<vector<P>> graph;

bool checkPath(int weight, int start, int end) {
    queue<int> q;
    bool visit[MAX+1] = {false, };

    visit[start] = true;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        if(cur == end) return true;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextW = graph[cur][i].second;

            if(nextW < weight || visit[next]) continue;

            q.push(next);
            visit[next] = true;
        }
    }

    return false;
}

void getMaximumWeight(int start, int end) {
   int left, right, mid, result = 0;
   left = 1;
   right = INF;

   while(left <= right) {
       mid = (left + right) / 2;

       bool isValid = checkPath(mid, start, end);

       if(isValid) {
           left = mid + 1;
           if(result < mid) result = mid; 
       } else {
           right = mid - 1;
       }
   }

   cout << result << '\n';
}

int main() {
    int x, y, w, s, e;
    cin >> N >> M;

    for(int i = 0; i <= N; i++) 
        graph.push_back(vector<P>());
    
    for(int i = 0; i < M; i++) {
        cin >> x >> y >> w;

        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }

    cin >> s >> e;

    getMaximumWeight(s, e);

    return 0;
}