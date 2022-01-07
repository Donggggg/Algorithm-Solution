#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000001
using namespace std;

int N, H;
vector<int> up, down;

int main() {
    int u, d;
    int anum = 0, cnum = MAX;

    cin >> N >> H;
    
    for(int i = 0; i < N / 2; i++) {
        cin >> d >> u;
        down.push_back(d);
        up.push_back(u);
    }

    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    for(int i = 1; i <= H; i++) {
        int downIndex = lower_bound(down.begin(), down.end(), i) - down.begin();
        int upIndex = lower_bound(up.begin(), up.end(), H-i+1) - up.begin();
        int currentObs = N - (upIndex + downIndex);
        
        if(currentObs < cnum) {
            cnum = currentObs;
            anum = 1;
        } else if (currentObs == cnum) {
            anum++;
        }
    }

    cout << cnum << ' ' << anum << '\n';

    return 0;
}
