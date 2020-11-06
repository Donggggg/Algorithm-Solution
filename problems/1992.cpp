#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int **photo, N;

void zip(int n, int x, int y)
{
	int mark = photo[x][y];
	int more = 0;

	for(int i = x; i < x+n; i++)
		for (int j = y; j < y + n; j++) 
			if (mark != photo[i][j]) 
				more = 1;
	
	if (more == 1) {
		printf("(");
		zip(n / 2, x, y);
		zip(n / 2, x, y + n / 2);
		zip(n / 2, x + n / 2, y);
		zip(n / 2, x + n / 2, y + n / 2);
		printf(")");
	}
	else {
		printf("%d", mark);
	}
}

int main() 
{
	scanf("%d", &N);
	photo = new int*[N];

	for (int i = 0; i < N; i++) {
		photo[i] = new int[N];
		for (int j =0; j < N; j++) {
			scanf("%1d", &photo[i][j]);
		}
	}

	zip(N, 0, 0);
}
