#include <iostream>
#include <vector>
#include <math.h>
#define P pair<long,long>
#define MAX_BIN 1024
using namespace std;

int N;
vector<P> flavors;
long long arr[MAX_BIN], ans = 1e10;

void getMinimumDiff(int idx, int bin, P flavor) {
    if(arr[bin] == 0) {
        arr[bin] = abs(flavor.first - flavor.second);
        if(ans > arr[bin]) ans = arr[bin];
    }
    
    for(int i = idx + 1; i < N; i++) {
        int nextBin = bin + pow(2, i);

        if(arr[nextBin] == 0)
            getMinimumDiff(i, nextBin, {flavor.first * flavors[i].first, flavor.second + flavors[i].second});
        getMinimumDiff(i, bin, flavor);
    }
}

int main() {
    int x, y;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        flavors.push_back({x,y});
    }

    for(int i = 0; i < N; i++)
        getMinimumDiff(i, pow(2,i), flavors[i]);

    cout << ans << '\n';

    return 0;
}