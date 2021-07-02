#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    int n;
    string log;
    set<string> company;
    // 자동 정렬 (오름차순)
    // 입력, 삭제, 조회 -> 시간복잡도가 효율 굳. O(logN)
    // 중복된 원소 X

    cin >> n;
    getchar();

    while(n--)
    {
        getline(cin, log); // 공백을 포함해서 입력을 받음
        
        int space_pos = log.find(" ");
        string name = log.substr(0, space_pos);
        string cmd = log.substr(space_pos+1, 5);
        
        if(cmd.compare("enter") == 0) 
            company.insert(name);
        else 
            company.erase(name);
    }

    for(set<string>::reverse_iterator it = company.rbegin(); it != company.rend(); it++)
        cout << *it << '\n';

    return 0;
}