#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;

int N;
int alpha[26];
vector<string> dicts;

int main() {
    int cur = 9, sum = 0;
    string str;
    
    memset(alpha, 0, sizeof(alpha));

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> str;
        dicts.push_back(str);
    }

    sort(dicts.begin(), dicts.end());

    for(int i = 0; i < N; i++) {
        int len = dicts[i].length();

        for(int j = 0; j < len; j++) {
            int c = dicts[i][j] - 'A';
            alpha[c] += pow(10, len - j - 1);
        }
    }

    sort(alpha, alpha + 26, greater<>());

    for(int i = 0; i < 26; i++, cur--) 
        if(alpha[i] > 0)
            sum += cur * alpha[i];
    
    cout << sum << '\n';

    return 0;
}