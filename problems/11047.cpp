#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() 
{
    int N, K, cnt = 0, price = 0, cur = 0;
    int arr[10];

   scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
       scanf("%d", &arr[i]);

    sort(arr, arr+N, greater<int>());

    while (1) {
        while(1) { 
            price += arr[cur];
            if(price > K) {
                price -= arr[cur];
                break;
            }
            cnt++;
        }
        
        if(price == K)
            break;
        cur++;
    }

    printf("%d\n", cnt);

    return 0;
}