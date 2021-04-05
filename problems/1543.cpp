#include <iostream>
using namespace std;

int pos = 0, cnt = 0;
string doc, keyword;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // ' '을 포함해서 받을 수 있음
    getline(cin, doc);
    getline(cin, keyword);

    while(pos < doc.length())
    {
        if(!doc.compare(pos, keyword.length(), keyword)) { // 검색어와 일치한 경우
            cnt++;
            pos += keyword.length();
        } else { // 일치하지 않는 경우
            pos++;
        }
    }

    cout << cnt << '\n';

    return 0;
}