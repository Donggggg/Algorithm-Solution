#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#define MAX 1004000
using namespace std;

int main()
{
    int a;

    cin >> a;

    if (a == 1) {
        cout << 2 << '\n';
        return 0;
    }

    for (int i = a; i <= MAX; i++) {
        string str = to_string(i);
        string rstr = str;
        reverse(rstr.begin(), rstr.end());

        if(str == rstr) {
            bool isValid = true;

            for(int j = 2; j <= sqrt(i); j++) {
                if(i % j == 0) {
                    isValid = false;
                    break;
                }
            }

            if(isValid) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}