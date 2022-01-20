#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N, K;
vector<int> students;
map<int,int> smap;
map<int,int>::iterator it;

int main() {
    int left, right;
    long long cnt = 0;
    string name;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> name;
        students.push_back(name.length());
    }

    left = 0;
    right = 0;

    while (right - left <= K) {
        it = smap.find(students[right]);
        if (it == smap.end()) smap.insert({students[right], 1});
        else it->second++;
        right++;
    }
    right--;

    while(left < N) {
        int wsize = right - left;

        if(wsize < K) {
            right++;
            if(N <= right) continue;
            it = smap.find(students[right]);
            if (it == smap.end()) smap.insert({students[right], 1});
            else it->second++;
        }
        else if(wsize == K) {
            it = smap.find(students[left]);
            cnt += it->second - 1;
            if (it->second > 1) it->second--;
            else smap.erase(students[left]);
            left++;
        }
    }

    cout << cnt << '\n';

    return 0;
}