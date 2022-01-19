#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define P pair<int,int>
#define MAX 1e9
using namespace std;

int N, M;
vector<P> list;
map<int,int>::iterator it;

int findMinimumDiff() {
    int left, right, answer, curMin;
    map<int,int> counts;

    left = right = 0;
    answer =  MAX;

    while(right < list.size()) {
       while(counts.size() != N && right < list.size()) {
           it = counts.find(list[right].second);
           if(it == counts.end()) counts.insert({list[right].second, 1});
           else it->second++;
           right++;
       }

       while(counts.size() == N) {
           it = counts.find(list[left].second);

           if(it->second == 1) {
               counts.erase(list[left].second);
               left++;
               answer = min(answer, list[right-1].first - list[left-1].first);
               break;
           }
           else it->second--;

           left++;
       }
    }

    return answer;
}

int main() {
    int x;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> x;
            list.push_back({x, i});
        }
    }

    sort(list.begin(), list.end());

    cout << findMinimumDiff() << '\n';

    return 0;
}