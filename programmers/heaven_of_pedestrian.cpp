#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int dp[500][500][2];
    memset(dp, 0, sizeof(dp));
    
    
    for(int i = 0; i < m; i++) {
        if(city_map[i][0] == 1)
            break;
        dp[i][0][0] = 1;
   }
    for(int i = 0; i < n; i++) {
        if(city_map[0][i] == 1)
            break;
        dp[0][i][1] = 1;
    }
   
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            
            if(city_map[i-1][j] == 0) {
                dp[i][j][0] += (dp[i-1][j][0]+dp[i-1][j][1]) % MOD;
            }
            if (city_map[i-1][j] == 2) {
                dp[i][j][0] += (dp[i-1][j][0] % MOD);
            }
               
            if(city_map[i][j-1] == 0) {
                dp[i][j][1] += (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
            }
                if (city_map[i][j-1] == 2) {
                dp[i][j][1] += (dp[i][j-1][1] % MOD);
            }  
        }
    }
    
    return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
}