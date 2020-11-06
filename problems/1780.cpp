#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int **paper, N, mi_one, pl_one, zero;

void cut(int n, int x, int y)
{
	int mark = paper[x][y];
	int more = 0;

	for(int i = x; i < x+n; i++)
		for (int j = y; j < y + n; j++) 
			if (mark != paper[i][j]) 
				more = 1;
	
	if (more == 1) {
		cut(n / 3, x, y);
		cut(n / 3, x, y + n / 3);
		cut(n / 3, x, y + n / 3 * 2);
		cut(n / 3, x + n / 3, y);
		cut(n / 3, x + n / 3, y + n / 3);
		cut(n / 3, x + n / 3, y + n / 3 * 2);
		cut(n / 3, x + n / 3 * 2, y);
		cut(n / 3, x + n / 3 * 2, y + n / 3);
		cut(n / 3, x + n / 3 * 2, y + n / 3 * 2);
	}
	else if (mark == -1)
		mi_one++;
	else if (mark == 1)
		pl_one++;
	else if (mark == 0)
		zero++;
}

int main() 
{
	scanf("%d", &N);
	paper = new int*[N];
	mi_one = pl_one = zero = 0;

	for (int i = 0; i < N; i++) {
		paper[i] = new int[N];
		for (int j =0; j < N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	cut(N, 0, 0);

	printf("%d\n%d\n%d\n", mi_one, zero, pl_one);
}
