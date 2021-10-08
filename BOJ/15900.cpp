#include <iostream>
#include <utility>
#include <vector>
#define MAX 500000
using namespace std;

int N;
vector<int> graph[MAX+1];
int visit[MAX + 1] = {0, };
int winner = false;

void dfs(int node, int depth)
{
    int isLeaf = true;
    for(int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if(!visit[next]) {
            isLeaf = false;
            visit[next] = true;
            dfs(next, depth + 1);
        }
    }
    if(isLeaf) winner = depth % 2 == 0 ? winner : !winner;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int x, y;
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    visit[1] = true;
    dfs(1, 0);
    winner ? cout << "Yes" << '\n' : cout << "No" << '\n';
    return 0;
} 