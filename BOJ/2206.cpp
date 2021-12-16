#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 1001
using namespace std;

int N, M;
int arr[MAX][MAX];
int visits[MAX][MAX][2];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

struct node {
    node(int x, int y, bool w) : x{x}, y{y}, w{w} {}
    int x;
    int y;
    bool w;
};

void searchShortestPath() {
    queue<node> q;

    q.push({0, 0, false});
    visits[0][0][0] = 1;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        bool w = q.front().w;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || N <= nx || M <= ny || (w && arr[ny][nx] == 1)) continue;

            if(arr[ny][nx] == 1 && !w) {
                q.push({nx, ny, true});
                visits[ny][nx][1] = visits[y][x][w] + 1;
            } 
            else if(arr[ny][nx] == 0 && !visits[ny][nx][w]) {
                q.push({nx, ny, w});
                visits[ny][nx][w] = visits[y][x][w] + 1;
            }
        }
    }
}

int main() {
    string str;
    cin >> M >> N;

    for(int i = 0; i < M; i++) {
        cin >> str;
        for(int j = 0; j < N; j++)
            arr[i][j] = str[j] - '0';
    }

    searchShortestPath();

    int answer1 = visits[M-1][N-1][0];
    int answer2 = visits[M-1][N-1][1];

    if(answer1 > 0 && answer2 > 0) cout << min(answer1, answer2) << '\n';
    else if (answer1 > 0) cout << answer1 << '\n';
    else if (answer2 > 0) cout << answer2 << '\n';
    else cout << -1 << '\n';

    return 0;
}