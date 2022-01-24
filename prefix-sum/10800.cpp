#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

struct Ball {
    int color;
    int sz;
    int idx;
};

int N;
vector<Ball> list;
int colors[MAX], sums[MAX], memo[MAX];

bool sizeCompare(Ball b1, Ball b2) {
    if(b1.sz == b2.sz) return b1.color < b2.color;
    return b1.sz < b2.sz;
}

int main() {
    int x, y, sum = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        list.push_back({x,y,i});
    }

    sort(list.begin(), list.end(), sizeCompare);

    for(int i = 0; i < N; i++) {
        colors[list[i].color] += list[i].sz;
        memo[list[i].sz] += list[i].sz;
        sum += list[i].sz;
        sums[list[i].idx] = sum - colors[list[i].color] - memo[list[i].sz] + list[i].sz;

        if(0 < i && list[i-1].sz == list[i].sz && list[i-1].color == list[i].color)
            sums[list[i].idx] = sums[list[i-1].idx];
    }

    for(int i = 0; i < N; i++) 
        cout << sums[i] << '\n';

    return 0;
}