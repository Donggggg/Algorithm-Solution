#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int fst, scd;

	while (1) {
		cin >> fst >> scd;

		if (fst == 0 && scd == 0)
			break;

		if (scd % fst == 0)
			printf("factor\n");
		else if (fst % scd == 0)
			printf("multiple\n");
		else
			printf("neither\n");
	}
}
