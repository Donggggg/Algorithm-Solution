#include <iostream>
#define MAX 100000
using namespace std;

int main() {
    int G;
    int start, end;
    bool isValid = false;
    
    cin >> G;

    start = end = 1;

    while(start <= MAX) {
        int res = (end * end) - (start * start);

        if(res < G) end++;
        else if(res > G) start++;
        else {
            cout << end << '\n';
            end++;
            isValid = true;
        }
    }

    if(!isValid)
        cout << -1 << '\n';

    return 0;
}