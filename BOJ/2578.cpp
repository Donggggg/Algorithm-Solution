#include <iostream>
#include <utility>
using namespace std;

int bingo[5][5], answer[5][5], cnt = 0;
bool current[5][5] = {false, };
int cx[5] = {0,1,};
int cy[5] = {4,3};

pair<int,int> findPosition(int num)
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(bingo[i][j] == num)
                return make_pair(i,j);
    return make_pair(-1,-1);
}

int getColumnBingo(pair<int,int> cur)
{
    for(int i = 0; i < 5; i++)
        if(current[i][cur.second] == false)
            return 0;
    return 1;
}

int getRowBingo(pair<int,int> cur)
{
    for(int i = 0; i < 5; i++)
        if(current[cur.first][i] == false)
            return 0;
    return 1;
}

int getCrossBingo(pair<int,int> cur)
{
    int sum = 0, i;
    int x = cur.first, y = cur.second;

    if(x == y) { // 우하향 대각
        for(i = 0; i < 5; i++) {
            if(current[i][i] == false) {
                break;
            }
        }
        if(i == 5)
            sum++;
    } 
    if(x == 4-y) { // 좌하향 대각
        for(i = 0; i < 5; i++) {
            if(current[i][4-i] == false) {
                break;
            }
        }
        if(i == 5)
            sum++;
    }
    
    return sum;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int sum = 0;
    pair<int,int> pos;

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> bingo[i][j];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> answer[i][j];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cnt++;
            pos = findPosition(answer[i][j]);
            current[pos.first][pos.second] = true;
            sum += (getColumnBingo(pos) + getRowBingo(pos) +  getCrossBingo(pos));
            if (sum > 2)
                break;
        }
        if (sum > 2)
            break;
    }

    cout << cnt << '\n';
    return 0;
}