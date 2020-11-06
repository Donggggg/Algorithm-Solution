#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int cnt = 0, N, r, c;

void search(int n, int x, int y)
{
	if (n == 2) {
		if (x == c && y == r) {
			printf("%d\n", cnt);
			return;
		}
		cnt++;
		if (x+1 == c && y == r) {
			printf("%d\n", cnt);
			return;
		}
		cnt++;
		if (x == c && y+1 == r) {
			printf("%d\n", cnt);
			return;
		}
		cnt++;
		if (x+1 == c && y+1 == r) {
			printf("%d\n", cnt);
			return;
		}
		cnt++;
	}
	else {
		search(n / 2, x, y);
		search(n / 2, x + n / 2, y);
		search(n / 2, x, y + n / 2);
		search(n / 2, x + n / 2, y + n / 2);
	}
}

int main() 
{
	scanf("%d %d %d", &N, &r, &c);
	search(pow(2, N), 0, 0);
}
