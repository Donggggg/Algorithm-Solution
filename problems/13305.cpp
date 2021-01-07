#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int main()
{
	int N, cheapPrice, curDist = 0;
	long long totalPrice = 0;
	scanf("%d", &N);
	int* distance = new int[N-1];
	int* price = new int[N];

	for (int i = 0; i < N - 1; i++)
		scanf("%d", &distance[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &price[i]);

	cheapPrice = price[0];

	for (int i = 0; i < N-1; i++) {
		if (cheapPrice > price[i]) {
			totalPrice += (long long)cheapPrice * curDist;
			curDist = 0;
			cheapPrice = price[i];
		}

		curDist += distance[i];
	}

	if (curDist > 0)
		totalPrice += (long long)cheapPrice * curDist;

	printf("%lld\n", totalPrice);

	return 0;
}
