#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int N, * arr, op[4];
long long max_ans, min_ans;

void find(int cur, long long res, int plus, int minus, int multi, int div)
{
	if(cur == N) {
		max_ans = max(max_ans, res);
		min_ans = min(min_ans, res);
		return ;
	}

	if(plus > 0){
		find(cur + 1, res+arr[cur], plus - 1, minus, multi, div);
	}
	if (minus > 0) {
		find(cur + 1, res-arr[cur], plus, minus - 1, multi, div);
	}
	if (multi > 0) {
		find(cur + 1, res*arr[cur], plus, minus, multi-1, div);
	}
	if (div > 0) {
		find(cur + 1, res/arr[cur], plus, minus, multi, div-1);
	}
}

int main() 
{
	max_ans = 0;
	min_ans = 1e+9;

	scanf("%d", &N);
	arr = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);
	
	find(1, arr[0], op[0], op[1], op[2], op[3]);

	printf("%lld\n%lld\n", max_ans, min_ans);
}
