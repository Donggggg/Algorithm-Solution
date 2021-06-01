#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int sz;
    string cmd, set;
    vector<int> list;
    cin >> T;

    while(T--)
    {
        cin >> cmd >> sz >> set;

        for(int i = 0; i < sz; i++)
            list.push_back(set[i*2+1]);

        cout << *(list.end()-1) << "\n";
    }


    return 0;
}