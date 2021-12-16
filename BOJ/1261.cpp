#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 101
using namespace std;

int N, M;
int arr[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

struct node {
    node(int x, int y, int w) : x{x}, y{y}, w{w} {}
    int x;
    int y;
    int w;
};

struct cmp {
    bool operator()(node &n1, node &n2) {
        return n1.w > n2.w;
    }
};

int searchShortestPath() {
    priority_queue<node, vector<node>, cmp> pq;
    bool visits[MAX][MAX] = {false, };

    pq.push({0, 0, 0});
    visits[0][0] = true;

    while(!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int w = pq.top().w;
        pq.pop();

        if(x == N - 1 && y == M - 1)
            return dist[y][x];

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nw = arr[ny][nx] == 0 ? w : w+1;

            if(nx < 0 || ny < 0 || N <= x || M <= y) continue;

            if(visits[ny][nx] && dist[ny][nx] > nw) {
                pq.push({nx, ny, nw});
                dist[ny][nx] = nw;
            } else if(!visits[ny][nx]){
                pq.push({nx, ny, nw});
                dist[ny][nx] = nw;
                visits[ny][nx] = true;
            }
        }
    }

    return -1;
}

int main() {
    string str;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> str;
        for(int j = 0; j < N; j++)
            arr[i][j] = str[j] - '0';
    }

    cout << searchShortestPath() << '\n';

    return 0;
}