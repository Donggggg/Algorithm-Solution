#include <iostream>
#include <string>
#include <math.h>
#define MAX 100
using namespace std;

int r1, c1, r2, c2;
int arr[MAX+1][MAX+1] = {0, };
int longest = 0;

int getNumberInSwirl(int r, int c) {
    int ar = abs(r);
    int ac = abs(c);
    int base = max(ar, ac);
    int tot = base * 2 + 1;

    if(ar < ac) {
        if(r < c) return (tot * tot - 6 * base) - (r + base);
        else return (tot * tot - 2 * base) - (base - r);
    } 
    else if (ar > ac) {
        if(r < c) return (tot * tot - 4 * base) - (c + base);
        else return (tot * tot) - (base - c);
    }
    else {
        if(r == c) {
            if(r < 0) return tot * tot - 4 * base;
            else return tot * tot;
        }
        else {
            if (r < c) return tot * tot - 6 * base;
            else return tot * tot - 2 * base;
        }
    }
}

void fillSwirl() {
    int x, y, num, dir, r, c;
    x = y = 0;

    for(int i = r1; i <= r2; i++, y++) 
        for(int j = c1, x = 0; j <= c2; j++, x++) {
            arr[y][x] = getNumberInSwirl(i, j);
            string str = to_string(arr[y][x]);
            longest = max((int)str.length(), longest);
        }
}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;

    fillSwirl();

    for(int i = 0; i <= r2-r1; i++) {
        for(int j = 0; j <= c2-c1; j++) {
            string str = to_string(arr[i][j]);
            if(str.length() != longest)  
                for(int s = 0; s < longest - str.length(); s++)
                    cout << ' ';
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}