#include <iostream>

using namespace std;
#define MAX 500000

int N, x, y;
long long W;
double ans, cnt = 0;
int arr[MAX+1]={0,};

int main()
{
    cin >> N >> W;

    for(int i = 1; i < N; i++) {
        cin >> x >> y;
        arr[x]++;
        arr[y]++;
    }

    for(int i = 2; i <= MAX; i++) { // 연결 정보가 1개인 >> 즉, 리프 노드 개수를 카운트 
        if(arr[i] == 1)
            cnt++;
    }

    ans = W / cnt; // 기대값 계산
    cout.precision(3); // (중요) : 오차 계산이 요구되어 필요함 10-3승
    cout << fixed << ans << "\n";

    return 0;
}