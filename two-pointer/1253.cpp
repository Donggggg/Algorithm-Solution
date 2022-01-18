#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> list;

int main() {
    int x, right, left, nices = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x;
        list.push_back(x);
    }

    sort(list.begin(), list.end());

    for(int i = 0; i < N; i++) {

        left = 0;
        right = N - 1;

        while(left < right) {
            // printf("%d %d => %d\n", left, right, i);
            int sum = list[left] + list[right];

            if(i != left && i != right) {
                if(sum == list[i]) {
                    nices++;
                    break;
                }
                sum < list[i] ? left++ : right--;
            }
            else if(i == left) left++;
            else if(i == right) right--;
        }
    }

    cout << nices << '\n';

    return 0;
}