#include <iostream>
#include <string>
#include <set>
using namespace std;

int N, M;
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string name;
    set<string> unknown, invisible, dbj;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> name;
        unknown.insert(name);
    }
     for(int i = 0; i < M; i++) {
        cin >> name;
        invisible.insert(name);
    }

    for(set<string>::iterator it = unknown.begin(); it != unknown.end(); it++) {
        string cur = *it;

        if(invisible.find(cur) != invisible.end()) 
            dbj.insert(cur);       
    }

    cout << dbj.size() << '\n';
    for(set<string>::iterator it = dbj.begin(); it != dbj.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}