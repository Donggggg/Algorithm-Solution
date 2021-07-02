#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 300

int N, l, x, y, num, board[MAX][MAX];
pair<int,int> current, destination;
queue<pair<int,int>> q;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;

    while(N--) {
        cin >> l;
        cin >> current.first >> current.second;
        cin >> destination.first >> destination.second;

        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < MAX; j++)
                board[i][j] = 0;

        q = queue<pair<int,int>>();
        q.push(current);
        board[current.first][current.second] = 1;

        while(!q.empty()) {
            current = q.front(); q.pop();
            x = current.first; y = current.second;

            if(x == destination.first && y == destination.second) {
                num = board[x][y] - 1;
                break;
            }

            if(x - 2 >= 0 && y + 1 < l && board[x-2][y+1] == 0) {
                q.push(make_pair(x-2, y+1));
                board[x-2][y+1] = board[x][y] + 1;
            }
            if(x - 1 >= 0 && y + 2 < l && board[x-1][y+2] == 0) {
                q.push(make_pair(x-1, y+2));
                board[x-1][y+2] = board[x][y] + 1;
            }
            if(x + 1 < l && y + 2 < l && board[x+1][y+2] == 0) {
                q.push(make_pair(x+1, y+2));
                board[x+1][y+2] = board[x][y] + 1;
            }
            if(x + 2 < l && y + 1 < l && board[x+2][y+1] == 0) {
                q.push(make_pair(x+2, y+1));
                board[x+2][y+1] = board[x][y] + 1;
            }
            if(x - 2 >= 0 && y - 1 >= 0 && board[x-2][y-1] == 0) {
                q.push(make_pair(x-2, y-1));
                board[x-2][y-1] = board[x][y] + 1;
            }
            if(x - 1 >= 0 && y - 2 >= 0 && board[x-1][y-2] == 0) {
                q.push(make_pair(x-1, y-2));
                board[x-1][y-2] = board[x][y] + 1;
            }
            if(x + 1 < l && y - 2 >= 0 && board[x+1][y-2] == 0) {
                q.push(make_pair(x+1, y-2));
                board[x+1][y-2] = board[x][y] + 1;
            }
            if(x + 2 < l && y - 1 >= 0 && board[x+2][y-1] == 0) {
                q.push(make_pair(x+2, y-1));
                board[x+2][y-1] = board[x][y] + 1;
            }
        }
        cout << num << "\n";

    }
    return 0;
}