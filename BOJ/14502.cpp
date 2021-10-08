#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define MAX 8
#define EMP 0
#define WALL 1
#define VIR 2
using namespace std;

int N, M;
int map[MAX][MAX] = {0, };
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<pair<int,int>> empts, virus;

int testScenario(int (*tmap)[MAX])
{
    int safes = 0;
    queue<pair<int,int>> q;
    bool visit[MAX][MAX] = {false, };
    for(int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
        visit[virus[i].first][virus[i].second] = true;
    }

    while(!q.empty())
    {
        pair<int,int> cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || N <= nx || M <= ny 
            || visit[nx][ny] || tmap[nx][ny] == VIR || tmap[nx][ny] == WALL) continue;
            q.push(make_pair(nx,ny));
            tmap[nx][ny] = VIR;
            visit[nx][ny] = true;
        }
    }

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++) 
            if(tmap[i][j] == EMP) safes++;
    return safes;
}

void solve ()
{
    int safeWidth = 0, tmap[MAX][MAX];
    for(int i = 0; i < empts.size(); i++)
        for(int j = i+1; j < empts.size(); j++)
            for(int k = j+1; k < empts.size(); k++) {
                copy(&map[0][0], &map[0][0]+MAX*MAX, &tmap[0][0]);
                tmap[empts[i].first][empts[i].second] = WALL;
                tmap[empts[j].first][empts[j].second] = WALL;
                tmap[empts[k].first][empts[k].second] = WALL;
                safeWidth = max(safeWidth, testScenario(tmap));
            }

    cout << safeWidth << '\n';
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            switch (map[i][j]) {
                case EMP:
                    empts.push_back(make_pair(i,j));
                    break;
                case VIR:
                    virus.push_back(make_pair(i,j));
                    break;
            }   
        }

    solve();
    return 0;
}