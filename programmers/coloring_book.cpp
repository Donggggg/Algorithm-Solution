#include <vector>
#include <algorithm>
#include <memory.h>
#define DIRECTS 4
using namespace std;

int M, N, width;
bool visit[110][110];
int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};

void eraseZone(int x, int y, int target, const vector<vector<int>> &pic)
{
    int nx, ny;
    visit[x][y] = true;
    width += 1;
    
    for(int i = 0; i < DIRECTS; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || M <= nx || N <= ny ||  visit[nx][ny])
            continue;
        if(pic[nx][ny] != target)
            continue;
        
        eraseZone(nx, ny, target, pic);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m;
    N = n;
    memset(visit,0,sizeof(visit));
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) 
            if(visit[i][j] == false && picture[i][j] != 0) {
                width = 0;
                eraseZone(i, j, picture[i][j], picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, width);
            }   

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}