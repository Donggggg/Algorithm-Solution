#include <iostream>
#include <string>
#include <set>
using namespace std;

int N;

int main()
{
    string str;
    set<string> company;
    cin >> N;
    getchar();

    while(N--)
    {
        getline(cin, str);
        int space_pos = str.find(" ");

        if(str[space_pos + 1] == 'e') {
            company.insert(str.substr(0,space_pos));
        } 
        else {
            company.erase(str.substr(0,space_pos));
        }
    }

    for(set<string>::reverse_iterator it = company.rbegin(); it != company.rend(); it++)
        cout << *it << '\n';

    return 0;
}