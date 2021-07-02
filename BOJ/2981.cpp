#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long gcd(long long num1, long long num2)
{
	long long tmp;

	if (max(num1, num2) == num2)
		swap(num1, num2);

	while (num1 % num2 != 0) {
		tmp = num2;
		num2 = num1 % num2;
		num1 = tmp;
	}
	return num2;
}

int main()
{
	cin.tie(NULL);
	int n;
	long long i, num;
	long long list[100];
	vector<long long> list2;

	cin >> n;

	for (i = 0; i < n; i++)
		cin >> list[i];

	sort(list, list + n);

	num = list[1] - list[0];

	for (i = 2; i < n; i++)
		num = gcd(num, list[i] - list[i - 1]); // 유클리드 호제법으로 최대공약수 구함

	list2.push_back(1);
	for (i = 2; i <= sqrt(num); i++) // 제곱근 아래 출력
		if (num % i == 0) {
			printf("%lld ", i);

			if (sqrt(num) != i)
				list2.push_back(i);
		}

	for (i = list2.size() - 1; i >= 0; i--) // 제곱근 이후 출력
		printf("%lld ", num / list2[i]);
}
