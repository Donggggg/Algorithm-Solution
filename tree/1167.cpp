#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100000
using namespace std;

vector<vector<pair<int,int>>> arr;
int mx = 0, maxNode;

void findMaximumNode(int startNode)
{
    int visit[MAX + 1] = {0, }, weight[MAX + 1] = {0, }, node;
    queue<int> q;
    q.push(startNode);
    visit[startNode] = true;

    while(!q.empty()) {
        node = q.front(); q.pop(); 

        for(int i = 0; i < arr[node].size(); i++) { 
            int v = arr[node][i].first;
            int w = arr[node][i].second;

            if(!visit[v]) { 
                q.push(v); 
                weight[v] = weight[node] + w; 
                visit[v] = true; 

                if(mx < weight[v]) {
                    mx = weight[v];
                    maxNode = v;
                }
            }
        }
    }
}

int main() {
    int n, x, y, w;
    vector<pair<int,int>> temp;
    cin >> n;
    arr.assign(MAX, temp);

    for(int i = 1; i <= n; i++) {
        cin >> x;
        while(1) {
            cin >> y;
            if(y < 0) break;
            cin >> w;
            arr[x].push_back({y, w});
        }
    }

    findMaximumNode(1);
    findMaximumNode(maxNode);

    cout << mx << "\n";
    return 0;
}