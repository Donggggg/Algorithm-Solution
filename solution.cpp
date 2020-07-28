#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, cnt =0 ;
	int time = 0, early, next, last=0;
	int meeting[100000][2];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> meeting[i][0] >> meeting[i][1];
		last = max(last, meeting[i][1]);
	}

	while (time <= last) {
		next = last;
		for (int i = 0; i < n; i++) {	
			if (time <= meeting[i][0]) {
				if (next != min(next, meeting[i][1]))
					early = meeting[i][0];
				next = min(next, meeting[i][1]);
			}
		}

		
			
		time = next;

		cnt++;
	}

	printf("%d\n", cnt);
}
