#include <iostream>
using namespace std;

int N;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    int count = 0;
    while(N > 0)
    {
        if(N%5 == 0) {
            count += N / 5;
            N = 0;
            break;
        }
        count++;
        N -= 3;
    }

    if(N > 0)
        cout << -1 << '\n';
    else
        cout << count << '\n';
    return 0;
}