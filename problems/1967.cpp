#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, x, y, w, parentNode, maxNode;
queue<int> q;
vector<vector<pair<int,int>>> arr;
vector<pair<int,int>> temp;
int visit[10001] = {0, }, weight[10001] = {0, }, mx = 0;

void findMaximumNode()1
{
    while(!q.empty()) {
        parentNode = q.front(); q.pop(); 

        for(int i = 0; i < arr[parentNode].size(); i++) { // 해당 노드의 자식들 탐색
            if(visit[arr[parentNode][i].first] == false) { // 아직 방문하지 않은 자식인 경우
                q.push(arr[parentNode][i].first); // 큐에 넣고
                weight[arr[parentNode][i].first] = weight[parentNode] + arr[parentNode][i].second; // 가중치 계산

                // 해당 노드의 가중치가 최대라면 최대 노드 갱신
                if(max(mx, weight[arr[parentNode][i].first]) == weight[arr[parentNode][i].first]) {
                    mx = weight[arr[parentNode][i].first];
                    maxNode = arr[parentNode][i].first;
                }
                visit[arr[parentNode][i].first] = true; // 해당 자식 노드 방문 표시
            }
        }
    }
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    arr.assign(10001, temp);
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> x >> y >> w;
        arr[x].push_back(make_pair(y,w));
        arr[y].push_back(make_pair(x,w));
    }

    // 가장 먼 노드를 찾기 위해 BFS 진행
    q.push(1);
    visit[1] = true;
    findMaximumNode();
    
    // 재탐색을 위한 변수 초기화
    memset(weight, 0, sizeof(int) * 10000);
    memset(visit, 0, sizeof(int) * 10000);

    // 가장 높은 가중치의 노드부터 다시 BFS 진행
    q.push(maxNode);
    visit[maxNode] = true;
    findMaximumNode();

    cout << mx << "\n";
    return 0;
}