#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int **paper, N, white, blue;

void cut(int n, int x, int y)
{
	int mark = paper[x][y];
	int more = 0;

	for(int i = x; i < x+n; i++)
		for (int j = y; j < y + n; j++) 
			if (mark != paper[i][j]) 
				more = 1;
	
	if (more == 1) {
		cut(n / 2, x, y);
		cut(n / 2, x, y + n / 2);
		cut(n / 2, x + n / 2, y);
		cut(n / 2, x + n / 2, y + n / 2);
	}
	else if (mark == 1)
		blue++;
	else if (mark == 0)
		white++;
}

int main() 
{
	scanf("%d", &N);
	paper = new int*[N];
	white = blue = 0;

	for (int i = 0; i < N; i++) {
		paper[i] = new int[N];
		for (int j =0; j < N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	cut(N, 0, 0);

	printf("%d\n%d\n", white, blue);
}
