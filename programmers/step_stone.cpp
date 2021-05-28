#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool checkValid(vector<int> stones, int k, int desc)
{
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++) {
        if(stones[i] < desc)
            cnt++;
        else
            cnt = 0;
        if(k <= cnt)
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int left, right, mid;
    left = 1; right = *max_element(stones.begin(), stones.end());
    
    while(left <= right) 
    {
        // printf("%d %d\n", left,right);
        mid = (left + right) / 2;        
  
        if(checkValid(stones, k, mid)) {
            left = mid + 1;
            answer = max(answer, mid);
        } else {
            right = mid - 1;
        }
    }
    // printf("%d %d\n", left,right);

    
    return answer;
}