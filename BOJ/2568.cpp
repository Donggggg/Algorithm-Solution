#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define MAX 500001
using namespace std;

int N;
int arr[MAX];
vector<int> list, seq, idx;
map<int,int> cs;
set<int> answer;

int main() {
    int x, y;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        arr[x] = y;
        cs.insert({y, x});
    }
    
    for(int i = 0; i < MAX; i++) {
        if(arr[i] != 0)
            list.push_back(arr[i]);
    }

    seq.push_back(-1);
    idx.assign(list.size(), 0);

    for(int i = 0; i < list.size(); i++) {
        if(list[i] <= seq.back()) {
           int index = lower_bound(seq.begin(), seq.end(), list[i]) - seq.begin();
           seq[index] = list[i];
           idx[i] = index;
        }
        else {
            seq.push_back(list[i]);
            idx[i] = seq.size()-1;
        }
    }

    int cur = seq.size() - 1;

    cout << N - (seq.size() - 1) << '\n';

    for(int i = list.size() - 1; 0 <= i; i--) {
        if(cur != idx[i]) answer.insert(cs.find(list[i])->second);
        else cur --;
    }

    for(auto item : answer) 
        cout << item << '\n';

    return 0;
}