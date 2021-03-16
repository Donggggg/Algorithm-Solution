#include <iostream>
#include <queue>

using namespace std;

int arr[100][100], check[100][100];
int N, maxHeight = 0, safeNum, ans = 1;

void resetArray(int height)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            if(height < arr[i][j])
                check[i][j] = -1;
            else
                check[i][j] = 0;
        }
}

void safeZone(int x, int y)
{
    queue<pair<int,int>> q;
    pair<int,int> cur;
    
    q.push(make_pair(x,y));
    check[x][y] = 1;

    while(!q.empty()) {
        cur = q.front(); q.pop();
        x = cur.first; y = cur.second;

        if(x+1 < N && check[x+1][y] == -1) {
            q.push(make_pair(x+1,y));
            check[x+1][y] = 1;
        }
        if(y+1 < N && check[x][y+1] == -1) {
            q.push(make_pair(x,y+1));
            check[x][y+1] = 1;
        }
        if(x-1 >= 0 && check[x-1][y] == -1) {
            q.push(make_pair(x-1,y));
            check[x-1][y] = 1;

        }
        if(y-1 >= 0 && check[x][y-1] == -1) {
            q.push(make_pair(x,y-1));
            check[x][y-1] = 1;
        }
    }


}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            maxHeight = max(arr[i][j], maxHeight);
        }

    for(int i = 1; i < maxHeight; i++) {
        resetArray(i);
        safeNum = 0;

        for(int x = 0; x < N; x++)
            for(int y = 0 ; y < N; y++) {
                if(check[x][y] == -1) {
                    safeNum++;
                    safeZone(x, y);
                }
            }
        ans = max(ans, safeNum);
    }

    cout << ans << "\n";

    return 0;
}