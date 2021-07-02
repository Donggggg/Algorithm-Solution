#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	unsigned int ans;
	int down = 1000000, up = 0;
	int n, tmp;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		down = min(down, tmp);
		up = max(up, tmp);
	}

	ans = up * down;

	printf("%d\n", ans);
}
