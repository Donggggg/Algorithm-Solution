/*
1. 연합이 발생하는 경우가 하나도 없을 때까지 아래 과정 반복
  1-1. (0,0)의 나라부터 상하좌우에 있는 나라와 인구를 비교해 연합 가능 여부를 체크한다.
    1-1-0. 타겟 나라와 연합이 가능하고 베이스 나라가 연합이 아니면 연합을 형성한다.
    1-1-1. 타겟 나라가 미연합 상태면 나라를 흡수해 연합한다.
    1-1-2. 타겟 나라가 연합 상태면 연합된 나라를 모두 흡수해 연합한다.
  1-2. 순회가 끝나면 연합 리스트를 순회하며 인구를 분배한다.
  1-3. 인구 분배 카운트를 증가시킨다.
2. 인구 분배 카운트를 출력하고 종료한다.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <memory.h>
#define MAX 50
using namespace std;

int N, L, R;
int map[MAX][MAX];
vector<vector<pair<int,int>>> unions;
bool unionTable[MAX][MAX];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int findUnionIndex(pair<int,int> conts)
{
    for(int i = 0; i < unions.size(); i++)
        for(int j = 0; j < unions[i].size(); j++) {
            int x = unions[i][j].first;
            int y = unions[i][j].second;
            if (conts.first == x && conts.second == y) return i;
        }
    return -1;
}

void unifyConts (pair<int,int> base, pair<int,int> target)
{
    if (!unionTable[base.first][base.second]) {
        vector<pair<int,int>> init;
        init.push_back(base);
        unions.push_back(init);
        unionTable[base.first][base.second] = true;
    }

    int baseIndex = findUnionIndex(base);

    if(!unionTable[target.first][target.second]) {
        unions[baseIndex].push_back(make_pair(target.first, target.second));
        unionTable[target.first][target.second] = true;
    } else {
        int targetIndex = findUnionIndex(target);
        if(baseIndex == targetIndex) return;
        for(int i = 0; i < unions[targetIndex].size(); i++) {
            unions[baseIndex].push_back(unions[targetIndex][i]);
        }
        unions.erase(unions.begin()+targetIndex);
    }
}

int immigrateWorld()
{
    int nx, ny, diff, uCnt = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            for(int d = 0; d < 4; d++) {
                nx = i + dx[d];
                ny = j + dy[d];
                if(nx < 0 || ny < 0 || N <= nx || N <= ny) continue;

                diff = abs(map[nx][ny] - map[i][j]);
                if (diff <= R && L <= diff) {
                    unifyConts(make_pair(i,j), make_pair(nx,ny));
                    uCnt++;
                }
            }
        }
    
    for(int i = 0; i < unions.size(); i++) {
        int sum = 0, avg;
        for(int j = 0; j < unions[i].size(); j++) sum += map[unions[i][j].first][unions[i][j].second];
        avg = sum / unions[i].size();
        for(int j = 0; j < unions[i].size(); j++) map[unions[i][j].first][unions[i][j].second] = avg;
    }

    return uCnt;
}

void solve()
{
    int cnt = 0, iCnt;
    while(true)
    {
        memset(unionTable, false, MAX*MAX);
        unions.clear();
        iCnt = immigrateWorld();
        if(!iCnt) break;
        cnt++;
    }

    cout << cnt << '\n';
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            cin >> map[i][j];

    solve();
    
    return 0;
}