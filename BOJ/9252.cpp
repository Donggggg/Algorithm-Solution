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

    if(list[0].length() > list[1].length()) {
        string temp = list[0];
        list[0] = list[1];
        list[1] = temp;
    }

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

    int len = table[len1][len2], start;
    string subseq;

    start = len2;
    for(int i = len1; 1 <= i; i--) {
        for(int j = start; 1 <= j; j--) {
            if(list[0][i-1] == list[1][j-1]) {
                start = j-1;
                subseq = list[0][i-1] + subseq;
                break;
            }
            else {
                if(table[i][j-1] > table[i-1][j]) continue;
                break;
            }
        }
    }


    cout << table[len1][len2] << '\n';
    if(table[len1][len2] != 0)
        cout << subseq << '\n';

    return 0;
}