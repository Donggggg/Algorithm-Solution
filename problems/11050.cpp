#include <iostream>
#include <algorithm>

using namespace std;

int com(int n, int k)
{
	if (k == 0)
		return 1;
	return com(n - 1, k - 1) * n;
}

int main()
{
	int n, k;

	cin >> n >> k;

	printf("%d\n", com(n, k) / com(k, k));
}
