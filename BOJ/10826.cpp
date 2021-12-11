#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;

int main()
{
    int n;
    string com;
    stack<int> stk;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> com;
        if (!com.compare("push")) {
            cin >> n;
            stk.push(n);
        }
        else if (!com.compare("top")) {
            if(stk.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << stk.top() << '\n'; 
        }
        else if (!com.compare("size")) 
            cout << stk.size() << '\n';
        else if (!com.compare("pop")) {
            if(stk.empty()) {
                cout << -1 << '\n';
                continue;
            }
            int num = stk.top();
            stk.pop();
            cout << num << '\n';
        }
        else if (!com.compare("empty")) 
            cout << stk.empty() << '\n';
    }

    return 0;
}