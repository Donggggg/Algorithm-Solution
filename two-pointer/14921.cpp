#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MAX 1e9
using namespace std;

int N;
vector<int> liqs;

int findClosestValue() {
    int left, right, closest = MAX; 

    left = 0;
    right = liqs.size() - 1;

    while(left < right) {
        int value = liqs[left] + liqs[right];

        if(value < 0) left++;
        else if(value > 0) right--;
        else return 0;

        if(abs(value) < abs(closest))
            closest = value;
    }

    return closest;
}

int main() {
    int x;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x;
        liqs.push_back(x);
    }

    cout << findClosestValue() << '\n';

    return 0;
}