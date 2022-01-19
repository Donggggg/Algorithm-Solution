#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define P pair<int, int>
using namespace std;

int N;
P lists[3];

bool maxCompare(P p1, P p2) {
    return p1.first < p2.first;
}

bool minCompare(P p1, P p2) {
    return p1.second < p2.second;
}

int getMaxItem(int idx) {
    switch (idx)
    {
    case 0:
        return max(lists[0].first, lists[1].first);
    case 1:
        return (*max_element(lists, lists + 3, maxCompare)).first;
    case 2:
        return max(lists[1].first, lists[2].first);
    }
    return -1;
}

int getMinItem(int idx) {
    switch (idx)
    {
    case 0:
        return min(lists[0].second, lists[1].second);
    case 1:
        return (*min_element(lists, lists + 3, minCompare)).second;
    case 2:
        return min(lists[1].second, lists[2].second);
    }
    return -1;
}

int main() {
    int input[3];
    int mins[3], maxs[3];
    cin >> N;

    cin >> input[0] >> input[1] >> input[2];
    lists[0] = make_pair(input[0], input[0]);
    lists[1] = make_pair(input[1], input[1]);
    lists[2] = make_pair(input[2], input[2]);

    for (int i = 1; i < N; i++) {
        cin >> input[0] >> input[1] >> input[2];

        for (int j = 0; j < 3; j++) {
            maxs[j] = input[j] + getMaxItem(j);
            mins[j] = input[j] + getMinItem(j);
        }

        for (int j = 0; j < 3; j++) {
            lists[j].first = maxs[j];
            lists[j].second = mins[j];
        }
    }

    cout << (*max_element(lists, lists + 3, maxCompare)).first << ' ' << (*min_element(lists, lists + 3, minCompare)).second << '\n';

    return 0;
}
