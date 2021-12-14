#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<pair<int,int>>> arr;
int mx = 0, maxNode;

void findMaximumNode(int startNode)
{
    int visit[10001] = {0, }, weight[10001] = {0, }, node;
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
    arr.assign(10001, temp);

    for(int i = 1; i < n; i++) {
        cin >> x >> y >> w;
        arr[x].push_back(make_pair(y,w));
        arr[y].push_back(make_pair(x,w));
    }

    findMaximumNode(1);
    findMaximumNode(maxNode);

    cout << mx << "\n";
    return 0;
}