#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int n, m;
    long long arr[1000000], ans = 0;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < m; i++) {
        sort(arr, arr+n);
        long long tmp = arr[0]+arr[1];
        arr[0] = tmp;
        arr[1] = tmp;
    }

    for(int i = 0 ; i < n; i++)
        ans += arr[i];

    printf("%lld\n", ans);

    return 0;
}