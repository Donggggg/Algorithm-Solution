#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {    
    string str, rstr;
    int answer = -1;
    int len = 0, right, left;

    cin >> str;
    rstr = str;
    reverse(rstr.begin(), rstr.end());


    if(str != rstr) {
        cout << str.length() << '\n';
        return 0;
    }

    right = str.length() - 1;
    left = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] != str[0]) {
            cout << str.length() - 1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}