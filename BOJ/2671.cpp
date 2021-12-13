#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    string str, cstr, ans;
    cin >> str;
    regex exp("((100+1+)|(01))+");
    ans = regex_match(str, exp) ? "SUBMARINE" : "NOISE";
    cout << ans << '\n';
    return 0;
}