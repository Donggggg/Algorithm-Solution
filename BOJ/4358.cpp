#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main()
{
    int cnt = 0;
    string str;
    map<string, int> kinds;

    while(getline(cin, str)) {
        if(kinds.find(str) == kinds.end()) {
            kinds.insert(make_pair(str, 1));
        } else {
            kinds.find(str)->second++;
        }
        cnt++;
    }

    for(map<string,int>::iterator it = kinds.begin(); it != kinds.end(); it++){
        cout<<fixed;
        cout.precision(4);
		cout << it->first << " " <<  it->second / (double)cnt * 100 << '\n';
	}


    return 0;
}