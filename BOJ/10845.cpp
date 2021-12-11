#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;

int main()
{
    int n;
    string com;
    queue<int> q;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> com;
        if (!com.compare("push")) {
            cin >> n;
            q.push(n);
        }
        else if (!com.compare("front")) {
            if(q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n'; 
        }
        else if (!com.compare("back")) {
            if(q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << q.back() << '\n'; 
        }
        else if (!com.compare("size")) 
            cout << q.size() << '\n';
        else if (!com.compare("pop")) {
            if(q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            int num = q.front();
            q.pop();
            cout << num << '\n';
        }
        else if (!com.compare("empty")) 
            cout << q.empty() << '\n';
    }

    return 0;
}