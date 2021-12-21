#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

string list[2];
int table[MAX+2][MAX+2];

int main() {
    int len1, len2;

    for(int i = 0; i < 2; i++)
        cin >> list[i];

    len1 = list[0].length();
    len2 = list[1].length();

    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(list[0][i-1] == list[1][j-1])
                table[i][j] = table[i-1][j-1] + 1;
            else 
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }

    cout << table[len1][len2] << '\n';

    return 0;
}