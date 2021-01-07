#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int end;
int arr[200001];

void pop()
{
	int cur, child;

	if (end == 1)
		printf("0\n");
	else {
		printf("%d\n", arr[1]);
		arr[1] = arr[--end];
		arr[end] = 0;
		cur = 1;

		while (1) {
			if (arr[cur * 2 + 1] == 0)
				child = cur * 2;
			else {
				if (abs(arr[cur * 2]) == abs(arr[cur * 2 + 1]))
					child = arr[cur * 2] < arr[(cur * 2) + 1] ? cur * 2 : (cur * 2) + 1;
				else
					child = abs(arr[cur * 2]) < abs(arr[(cur * 2) + 1]) ? cur * 2 : (cur * 2) + 1;
			}

			if (end <= child || abs(arr[cur]) < abs(arr[child]))
				break;

			if (abs(arr[cur]) == abs(arr[child])) {
				if (arr[cur] > arr[child]) 
					std::swap(arr[child], arr[cur]);
				else
					break;
			}
			else
					std::swap(arr[child], arr[cur]);

			cur = child;
		}
	}
}

void push(int num)
{
	int cur;

	arr[end] = num;
	cur = end++;

	while (1 < cur && abs(arr[cur / 2]) >= abs(arr[cur])) {
		if (abs(arr[cur / 2]) == abs(arr[cur])) {
			if (arr[cur / 2] > arr[cur])
				std::swap(arr[cur], arr[cur / 2]);
		}
		else 
			std::swap(arr[cur], arr[cur / 2]);
		
		cur /= 2;
	}
	
}

int main()
{
	int N, num;
	scanf("%d", &N);
	end = 1;

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		if (num == 0)
			pop();
		else
			push(num);
	}

	return 0;
}