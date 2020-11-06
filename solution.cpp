#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() 
{
	int N, * arr, dp[1010] = { 0, }, ans = 0;
	int now;

	scanf("%d", &N);
	arr = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		now = 0;
		for (int j = 0; j < i + 1; j++) {
			if (arr[j] > now && arr[i] > arr[j]) {
				dp[i]++;
				ans = max(ans, dp[i]);
				now = arr[j];
			}
		}
	}

	printf("%d\n", ans);
}
