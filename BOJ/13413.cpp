#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int T;

int main()
{
    int N, wb, bw;
    string origin, target;
    cin >> T;

    while (T--) {
        cin >> N;
        cin >> origin;
        cin >> target;

        wb = bw = 0;

        for (int i = 0; i < N; i++) 
            if (origin[i] != target[i]) 
             origin[i] == 'W' ? wb++ : bw++;    

        cout <<  min(wb, bw) + (int)abs(wb - bw) << '\n';
    }

    return 0;
}