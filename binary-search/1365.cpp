#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

int N;
vector<int> lines, arr;

int main() {
    int x;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x;
        lines.push_back(x);
    }

    arr.push_back(-1);

    for(int i = 0; i < N; i++) {
        if(lines[i] < arr.back()) 
            *(lower_bound(arr.begin(), arr.end(), lines[i])) = lines[i]; 
        else arr.push_back(lines[i]);
    }

    cout << N - (arr.size() - 1) << '\n';

    return 0;
}