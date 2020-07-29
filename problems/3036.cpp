#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, son, mom;
	int ring[100];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> ring[i];

	for (int i = 1; i < n; i++) {
		son = ring[0];
		mom = ring[i];

		for (int j = 2; j <= min(son, mom); j++) {
			if (son % j == 0 && mom % j == 0) {
				son /= j;
				mom /= j;
				j--;
			}
		}

		printf("%d/%d\n", son, mom);
	}
}
