#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <queue>
#include <utility>

using namespace std;

/*
city_map과 동일한 크기의 path_map을 만든다. 단 여기에는 경로의 가짓수를 적을것이다.
먼저 path_map의 [0][i]의 첫번째 행과 [i][0]의 첫번째 열을 채운다. 
 방법은, 먼저 첫번째 행부터 채우는데, 만약 city_map의 동일한 위치에 값이 1이라면 path_map에서 이후의 열을 전부 0으로 채운다. 만약 city_map의 동일한 위치에 값이 2라면 path_map에 0을 채운다. 만약 city_map의 동일한 위치에 값이 0이라면 path_map에 1을 채운다. 이런 방식으로 첫번째 열도 채운다.
 그다음 path_map의 [1][1]부터 시작해서 [n-1][m-1]까지 채워나간다. 
 방법은, 이전의 y값과 이전의 x값을 더하는 것이다. 
 예를들어, path_map[1][1]을 채우려면 
 먼저 city_map[0][1]의 값을 확인해서 1이라면, y에 0을 넣고, 2라면, 1또는 0을 만나거나 벽을 만날때까지 이전 y값을 확인한다. 만약 0을 만난다면 그 위치의 path_map 값을 y에 넣는다. 만약 찾던 도중 벽을 만나거나 1을 만난다면 0을 y에 넣는다.
 동일한 방식으로, city_map[1][0]의 값을 확인해서 1이라면, x에 0을 넣고, 2라면, 1또는 0을 만나거나 벽을 만날때까지 이전 x값을 확인한다. 만약 0을 만난다면 그 위치의 path_map값을 x에 넣는다. 만약 찾던 도중 벽을 만나거나 1을 만난다면 0을 x에 넣는다.
 x값과 y값을 찾은 다음에는 두 값을 더해서 path_map 위치에 넣는다.
 위 작업이 path_map[n-1][m-1]까지 진행된다면, 해당 값을 MOD로 나눠 나머지를 반환한다.
*/

int MOD = 20170805;
vector<vector<int>> city_map;
int m;
int n;
//--------내코드----------------------------------------------
int solution(int m, int n, vector<vector<int>> city_map) {
    queue<pair<int,int>> q;
    pair<int,int> cur;
    long long dp[500][500][2];
    bool visit[500][500];
    int dr[2] = {0,1}, dc[2] = {1,0};
    memset(dp, 0, sizeof(dp));
    memset(visit, false, sizeof(visit));
    
    q.push(make_pair(0,0));
    visit[0][0] = true;
    
    while(!q.empty())
    {
        int row, col;
        cur = q.front(); q.pop();
        row = cur.first;
        col = cur.second;
                
        if(row == 0)
            dp[row][col][0] = 1;
        if(col == 0)
            dp[row][col][1] = 1;
        
        if(col != 0 && row != 0) {
            int vsign = city_map[row-1][col];
            int hsign = city_map[row][col-1];
            
            if(hsign == 2 && vsign == 2) {
                dp[row][col][0] = dp[row][col-1][0];
                dp[row][col][1] = dp[row-1][col][1]; 
            } else if(hsign == 2) {
                dp[row][col][0] = (dp[row-1][col][0] + dp[row][col-1][0]) % MOD;
                dp[row][col][1] = 0;
            } else if(vsign == 2) {
                dp[row][col][0] = 0;
                dp[row][col][1] = (dp[row-1][col][1] + dp[row][col-1][1]) % MOD;
            } else {
                dp[row][col][0] = (dp[row-1][col][0] + dp[row][col-1][0]) % MOD;
                dp[row][col][1] = (dp[row-1][col][1] + dp[row][col-1][1]) % MOD;

            }
        }
    
        
        for(int i = 0; i < 2; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            
            if(nrow >= m || ncol >= n || visit[nrow][ncol] || city_map[nrow][ncol] == 1)
                continue;
            
            visit[nrow][ncol] = true;
            q.push(make_pair(nrow,ncol));
        }
    }    
                cout<<"내 정답: "<<(dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD<<endl;
            return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;

}
//--------------------------------------------------------

//정답 코드-------------------------------------------------------
int solution_answer(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    // 마지막 차원은 왼쪽에서 왔는지, 위에서 왔는지 => 왼쪽=0, 1=위쪽
    vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(n+1, vector<long long> (2)));

    // 0: 프리한 길
    // 1: 통행 금지
    // 2: 왼쪽에서 오던 차는 오른쪽으로만, 위에서 오던 차는 아래쪽으로만

    // 초기화
    for(int i = 0; i < m; i++) {
        if(city_map[i][0] == 1)
            break;
        dp[i][0][1] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(city_map[0][i] == 1)
            break;
        dp[0][i][0] = 1;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            // 바로 위 칸이 프리한 길이면
            if(city_map[i-1][j] == 0) {
                // 위에서 온 길의 수 += (위쪽칸에서 왼쪽으로 온 길의 수 + 위쪽칸에서 위쪽으로부터 온 길의 수)
                dp[i][j][1] += (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
            }
            // 바로 위 칸이 좌회전 우회전 금지 길이면
            if(city_map[i-1][j] == 2) {
                // 위에서 온 길의 수 += 위쪽칸에서 위쪽으로부터 온 길의 수
                dp[i][j][1] += (dp[i-1][j][1] % MOD);
            }
            // 바로 왼쪽칸이 프리한 길이면
            if(city_map[i][j-1] == 0) {
                // 왼쪽에서 온 길의 수 += 왼쪽칸에서 왼쪽으로부터 온 길의 수 + 윈쪽칸에서 위쪽으로부터 온 길의 수)
                dp[i][j][0] += (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
            }
            // 바로 왼쪽칸이 좌회전 우회전 금지 길이면
            if(city_map[i][j-1] == 2) {
                // 왼쪽에서 온 길의 수 += 왼쪽칸에서 윈쪽으로부터 온 길의 수
                dp[i][j][0] += (dp[i][j-1][0] % MOD);
            }
        }
    }

    answer = (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    cout<<"정답 코드: "<<answer<<endl;
    return answer;
}
//--------------------------------------------------------


int main(){
    cout<<"정답과 내답 비교 시작"<<endl;
    int ran; //0,1,2 
    vector<int> one_row; //city_map의 한 행
    int my_answer;
    int real_answer;
    srand(time(NULL));
    //총 10개의 테스트 케이스를 만들자.
    for(int count = 0; count<10000; count++){
        cout<<count+1<<"번째 시도"<<endl;
        city_map.clear();
        //n을 3부터 22사이 랜덤
        n = rand() % 20; //0~19사이
        n += 3; //3~22사이
        //cout<<"n: "<<n;
        //m을 3부터 22사이 랜덤
        m = rand() % 20; //0~19사이
        m += 3; //3~22사이
        //cout<<"  m: "<<m<<endl;
        //m행, n열 크기의 city_map 채우기
        for(int i = 0; i<m; i++){
            one_row.clear();
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0 || i==m-1 && j==n-1){
                    one_row.push_back(0);
                }
                else{
                    ran = rand() % 100;
                    if(ran>=0 && ran<10){//10%확률로 1
                        ran = 1;
                    }
                    else if(ran>=10 && ran<70){ //60%확률로 0
                        ran = 0;
                    }
                    else{ //30%확률로 2
                        ran = 2;
                    }
                    one_row.push_back(ran);
                }
            }
            city_map.push_back(one_row);
        }

        my_answer = solution(m, n, city_map); //내코드 먼저
        real_answer = solution_answer(m, n, city_map); //정답코드
        if(my_answer != real_answer){
            cout<<"예외케이스 찾음: "<<count+1<<"번째"<<endl;
        }
        cout<<endl;
    }
}