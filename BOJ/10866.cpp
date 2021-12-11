#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N;

int main()
{
    int n;
    string com;
    deque<int> q;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> com;
        if (!com.compare("push_front")) {
            cin >> n;
            q.push_front(n);
        }
        else if (!com.compare("push_back")) {
            cin >> n;
            q.push_back(n);
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
        else if (!com.compare("pop_front")) {
            if(q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            int num = q.front();
            q.pop_front();
            cout << num << '\n';
        }
        else if (!com.compare("pop_back")) {
            if(q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            int num = q.back();
            q.pop_back();
            cout << num << '\n';
        }
        else if (!com.compare("empty")) 
            cout << q.empty() << '\n';
    }

    return 0;
}