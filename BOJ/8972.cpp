#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#define P pair<int,int>
using namespace std;

int R, C;
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1}, dy[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
P player;
int ardnum[100][100];
vector<string> board;
vector<P> arduinos;

int main() {
    string str;
    string order;

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        cin >> str;
        board.push_back(str);

        for(int j = 0; j < str.length(); j++) {
            if(str[j] == 'I') player = make_pair(j, i);
            else if(str[j] == 'R') {
                arduinos.push_back({j, i});
                ardnum[i][j] = 1;
            }
        }
    }

    cin >> order;

    for(int i = 0; i < order.length(); i++) {
        int command = order[i] - '0' - 1;

        board[player.second][player.first] = '.';
        player.first += dx[command];
        player.second += dy[command];
        board[player.second][player.first] = 'I';

        if(ardnum[player.second][player.first] > 0) {
            cout << "kraj " << i + 1 << '\n';
            return 0;
        }
        
        for(int j = 0; j < arduinos.size(); j++) {
            int x, y, nx, ny, mini, nextX, nextY, dist, oriX, oriY;
            x = arduinos[j].first;
            y = arduinos[j].second;
            mini = 201;

            for(int d = 0; d < 9; d++) {
                nx = x + dx[d];
                ny = y + dy[d];
                dist = abs(nx - player.first) + abs(ny - player.second);
                
                if(dist < mini) {
                    mini = dist;
                    oriX = x;
                    oriY = y;
                    nextX = nx;
                    nextY = ny;
                }
            }

            if(player.first == nextX && player.second == nextY) {
                cout << "kraj " << i + 1 << '\n';
                return 0;
            }


            ardnum[oriY][oriX]--;
            ardnum[nextY][nextX]++;
            board[oriY][oriX] = '.';
            board[nextY][nextX] = 'R';
            arduinos[j] = make_pair(nextX, nextY);
        }

        vector<P> newArds;

        for(int j = 0; j < arduinos.size(); j++) {
            if(ardnum[arduinos[j].second][arduinos[j].first] < 2) {
                newArds.push_back({arduinos[j].first, arduinos[j].second});
                if(ardnum[arduinos[j].second][arduinos[j].first] < 0) {
                    ardnum[arduinos[j].second][arduinos[j].first] = 0;
                    board[arduinos[j].second][arduinos[j].first] = '.';
                }
                else board[arduinos[j].second][arduinos[j].first] = 'R';
            }
            else 
                board[arduinos[j].second][arduinos[j].first] = '.';
        }

         for(int j = 0; j < arduinos.size(); j++) {
            if(ardnum[arduinos[j].second][arduinos[j].first] > 1)
                ardnum[arduinos[j].second][arduinos[j].first] = 0;
        }

        arduinos = newArds;
    }

    for(int i = 0; i < R; i++)
        cout << board[i] << '\n';

    return 0;
}