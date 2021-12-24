#include <iostream>
#include <string>
#include <set>
#include <queue>
#define P pair<int,int>
#define MAX 1500
using namespace std;

int R, C;
vector<string> lake;
set<P> lasts;
set<P> waters;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool visits[MAX][MAX];

bool checkReachable() {
    queue<P> q;
    set<P> newLasts;
    set<P>::iterator iter;

    for(iter = lasts.begin(); iter != lasts.end(); iter++) {
        q.push(*iter);
        visits[iter->second][iter->first] = true;
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || C <= nx || R <= ny || visits[ny][nx]) 
                continue;
            
            if(lake[ny][nx] == 'X') {
                newLasts.insert({nx, ny});
                continue;
            }

            if(lake[ny][nx] == 'L') 
                return true;

            visits[ny][nx] = true;
            q.push({nx, ny});
        }
    }

    lasts = newLasts;

    return false;
}

void updateLake() {
    set<P>::iterator iter;
    set<P> newWaters;

    for(iter = waters.begin(); iter != waters.end(); iter++) {
        for(int i = 0; i < 4; i++) {
            int nx = iter->first + dx[i];
            int ny = iter->second + dy[i];

            if(nx < 0 || ny < 0 || C <= nx || R <= ny) continue;

            if(lake[ny][nx] == 'X') {
                lake[ny][nx] = '.';
                newWaters.insert({nx, ny});
            }
        }
    }

    waters = newWaters;
}

int main() {
    string str;
    P swan;
    int curDay = 0;

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        cin >> str;
        lake.push_back(str);

        for(int j = 0; j < C; j++) {
            if(str[j] == '.') 
                waters.insert({j, i});
            else if(str[j] == 'L') {
                swan = make_pair(j, i);
                waters.insert({j, i});
            }
        }
    }

    lasts.insert(swan);

    while(1) {
        if(checkReachable())
            break;

        updateLake();
        curDay++;
    }

    cout << curDay << '\n';

    return 0;
}