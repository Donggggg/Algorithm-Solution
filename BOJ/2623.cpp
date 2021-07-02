#include <iostream>
#include <vector>
using namespace std;

int n, num;
vector<int> pd[1000];

int main()
{
     cin.tie(NULL); ios_base::sync_with_stdio(false);

    num = 0;
    while (1)
    {
        cin >> n;
        cout << n;
        if (n == '\n')
            num++;
        else if (n == -1)
            break;
        else
        {
            pd[num].push_back(n);
        }
    }

    return 0;
}