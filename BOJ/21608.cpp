#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#define LIKE_NUM 4
using namespace std;

int N;
vector<vector<int>> list;
int map[30][30] = {0, };
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool isExist(int target, int student)
{
    for(int i = 0; i < LIKE_NUM; i++) 
        if(list[student][i] == target)
            return true;
    return false;
}

vector<pair<int,int>> findPopularSeat(int number)
{
    int preferrMap[30][30] = {0, };
    vector<pair<int,int>> candis;

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) {
            if(map[i][j] != 0) continue;
            
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || ny < 0 || N <= nx || N <= ny) continue;
                if(isExist(map[nx][ny], number)) cnt++;
            }
            preferrMap[i][j] = cnt;
        }

        int max = -1;
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < N; j++) {
                if(max < preferrMap[i][j]) {
                    max = preferrMap[i][j];
                    candis.clear();
                    candis.push_back(make_pair(i,j));
                } else if(max == preferrMap[i][j]) {
                    candis.push_back(make_pair(i,j));
                }
            }
            return candis;
}

vector<pair<int,int>> findEmptySeat(vector<pair<int,int>> seat)
{
    int nx,ny;
     int preferrMap[30][30] = {0, };
     vector<pair<int,int>> candis;

    for(int i = 0; i < seat.size(); i++) {
        int x = seat[i].first;
        int y = seat[i].second;

        int cnt = 0;
        for(int j = 0; j < LIKE_NUM; j++) {
            nx = x + dx[j];
            ny = y + dy[j];
            if(0 <= nx && 0 <= ny && nx < N && ny < N && map[nx][ny] == 0 && map[x][y] == 0) cnt++;
        }
                // printf("%d %d > %d\n",x,y,cnt);

        preferrMap[x][y] = cnt;
    }

    int max = -1;
     for(int i = 0; i < seat.size(); i++) {
        int x = seat[i].first;
        int y = seat[i].second;
        if (max < preferrMap[x][y]) {
            max = preferrMap[x][y];
            candis.clear();
            candis.push_back(make_pair(x, y));
        } else if (max == preferrMap[x][y]) {
            candis.push_back(make_pair(x, y));
        }
     }
     return candis;
}

vector<pair<int,int>> findAnySeat(vector<pair<int,int>> seat)
{
    vector<pair<int,int>> candis;

    for(int i = 0; i < seat.size(); i++) {
        int x = seat[i].first;
        int y = seat[i].second;
        if(map[x][y] == 0) {
            candis.push_back(make_pair(x,y));
            return candis;
        }
    }

    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++) {
        if(map[i][j] == 0) {
             candis.push_back(make_pair(i,j));
            return candis;
        }
    }
    return candis;
}

void setStudent (int number) 
{
    vector<pair<int,int>> seat;
    seat = findPopularSeat(number);
    int c = 0;
    if(seat.size() > 1) {
        seat = findEmptySeat(seat);
        c = 1;
        if(seat.size() > 1) {
            seat = findAnySeat(seat);
            c = 2;
        }
    }
    map[seat[0].first][seat[0].second] = number;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, t;
    vector<int> orders;

    cin >> N;
    list.assign(401, vector<int>());
    for(int i = 0; i < N*N; i++) {
        cin >> n;
        orders.push_back(n);
        for(int j = 0; j < LIKE_NUM; j++) {
            cin >> t;
            list[n].push_back(t);
        }
    }

    for(int i = 0; i < orders.size(); i++) {
        setStudent(orders[i]);
    }

    int score = 0;
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++) {
            int cnt = 0;
            for (int a = 0; a < 4; a++) {
                int nx = x + dx[a];
                int ny = y + dy[a];
                if (nx < 0 || ny < 0 || N <= nx || N <= ny)
                    continue;
                if (isExist(map[nx][ny], map[x][y]))
                    cnt++;
            }
            score += pow(10, cnt - 1);
        }
    cout << score << '\n';

    return 0;
}