#include <iostream>
using namespace std;

int N, M, answer;
int arr[100];

int main()
{
    int tmp, sum, diff;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i = 0; i < N; i++) 
        cin >> arr[i];

    // 각 for문이 n번째 카드 인덱스
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            for(int k = j+1; k < N; k++) {
                sum = arr[i] + arr[j] + arr[k];
                diff = M - sum;

                // 현재 카드합이 M에 더 가까우면 갱신
                if(diff < M - answer && -1 < diff)
                    answer = sum;
                
                // 블랙잭인 경우 처리
                if(answer == M) {
                    cout << answer << '\n';
                    return 0;
                }
            }

    cout << answer << '\n';
    return 0;
}