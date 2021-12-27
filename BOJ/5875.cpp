#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int numOpen, numClose, numTotal;
    string braks;
    vector<int> openHistory, closeHistory;
    deque<int> openStack, closeStack;

    cin >> braks;

    numOpen = numClose = numTotal = 0;

    for(int i = 0; i < braks.length(); i++) {
        if(braks[i] == '(') {
            numOpen++;
            numTotal++;
            openStack.push_back(i);
        }
        else {
            numClose++;
            numTotal--;
            if(!openStack.empty()) {
                openStack.pop_back();
            }
            else {
                closeStack.push_back(i);
            }
        }

        openHistory.push_back(numOpen);
        closeHistory.push_back(numClose);
    }

    if(numTotal > 0) {
        cout << openHistory[openHistory.size()-1] - openHistory[openStack.back()] + 1 << '\n';
    }
    else if(numTotal < 0) {
        cout << closeHistory[closeStack.front()] << '\n';
    }
    else cout << 0 << '\n';

    return 0;
}