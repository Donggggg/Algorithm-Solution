#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int range = 10;
    string str;

    cin >> str;

    while(str.length() > range) {
        cout << str.substr(range-10, 10) << '\n';
        range += 10;
    }

    cout << str.substr(range - 10) << '\n';

    return 0;
}