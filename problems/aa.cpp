#include <iostream>
using namespace std;

int N;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    int count = 0;
    while(1)
    {
        if(N%5 == 0) {
            count++;
            N -=5;
            continue;
        }
        else if(N%3 == 0) {
            count++;
            N -= 3;
            continue;
        }
            break;
    }

    if(N > 0)
        cout << -1 << '\n';
    else
        cout << count << '\n';
    return 0;
}