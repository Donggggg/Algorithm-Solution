#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int start = 0, count = 0, sum = 0, tmp;
	int list[50];
	string str;

	cin >> str;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			list[count] = stoi(str.substr(start, i - start));
			start = i + 1;
			count++;
			list[count] = str[i] - '-' - 1;
			count++;
		}
	}
	count--;

	for (int i = 0; i < count; i++) {
		if (list[i] == -3) // '+'인 경우
			continue;
		else if (list[i] == -1) { // '-'인 경우
			tmp = 0;
			i++;
			while (list[i] != -1 && i < count) {
				if (list[i] == -3)
					i++;
				else 
					tmp += list[i++];									
			}
			i--;
			sum -= tmp;
		}
		else // 숫자인 경우
			sum += list[i];
	}	

	printf("%d\n", sum);
}
