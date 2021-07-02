#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T, N, top;
    int arr[1000000];
    long long ans;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        ans = 0;
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[j]);

        top = arr[N - 1];

        for (int k = N - 1; 0 <= k; k--)
        {
            if (top > arr[k]) // 상한가보다 낮으면 차액 추가
                ans += top - arr[k];
            else if (top < arr[k]) // 상한가보다 높으면 상한가 갱신
                top = arr[k];
        }

        printf("%lld\n", ans);
    }

    return 0;
}