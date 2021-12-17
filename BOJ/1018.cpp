#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<string> board;

int calculate(int x, int y) {
    int w, b;
    bool flag = true;

    w = b = 0;

    for(int i = y; i < y + 8; i++) {
        for(int j = x; j < x + 8; j++) {
            if(flag) {
                if(board[i][j] == 'W') b++;
                if(board[i][j] == 'B') w++;
            }
            else {
                if(board[i][j] == 'B') b++;
                if(board[i][j] == 'W') w++;
            }
            flag = !flag;
        }
        flag = !flag;
    }
    
    return min(w,b);
}

int main() {
    string str;
    int ans = 64;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> str;
        board.push_back(str);
    }

    for(int i = 0; i <= N - 8; i++)
        for(int j = 0; j <= M - 8; j++) 
            ans = min(ans, calculate(j, i));

    cout << ans << '\n';

    return 0;
}