#include <iostream>
#include <string>
#include <vector>
#include <stack>
#define MAX 1000000000
using namespace std;

vector<string> command;
stack<long long> s;

bool executeCase(long long num)
{
    long long n, n1, n2;
    s.push(num);

    for(int i = 0; i < command.size(); i++) {
        string c = command[i];
        if (!c.substr(0,3).compare("NUM")) {
            n = stoi(c.substr(3));
            if(n < 0 || MAX < n) return false;
            s.push(n);
        } else if (c == "POP") {
            if(s.size() < 1) return false;
            s.pop();
        } else if (c == "INV") {
            if(s.size() < 1) return false;
            n = s.top(); s.pop();
            s.push(-n);
        } else if (c == "DUP") {
            if(s.size() < 1) return false;
            n = s.top();
            s.push(n);
        } else if (c == "SWP") {
            if(s.size() < 2) return false;
            n1 = s.top(); s.pop();
            n2 = s.top(); s.pop();
            s.push(n1);
            s.push(n2);
        } else if (c == "ADD") {
            if(s.size() < 2) return false;
            n1 = s.top(); s.pop();
            n2 = s.top(); s.pop();
            if(MAX < abs(n1 + n2)) return false;
            s.push(n1 + n2);
        } else if (c == "SUB") {
            if(s.size() < 2) return false;
            n1 = s.top(); s.pop();
            n2 = s.top(); s.pop();
            if(MAX < abs(n2 - n1)) return false;
            s.push(n2 - n1);
        } else if (c == "MUL") {
            if(s.size() < 2) return false;
            n1 = s.top(); s.pop();
            n2 = s.top(); s.pop();
            if(MAX < abs(n1 * n2)) return false;
            s.push(n2 * n1);
        } else if (c == "DIV") {
            if(s.size() < 2) return false;
            int cnt = 0;
            n1 = s.top(); s.pop();
            n2 = s.top(); s.pop();
            if(n1 == 0) return false;

            long long res = abs(n2 / n1);
            if(n1 < 0) cnt++; if(n2 < 0) cnt++;
            if(cnt == 1) res *= -1; 
            s.push(res);
        } else if (c == "MOD") {
            if(s.size() < 2) return false;
            n1 = s.top(); s.pop();
            n2 = s.top(); s.pop();
            if(n1 == 0) return false;

            long long res = abs(n2) % abs(n1);
            if(n2 < 0) res *= -1; 
            s.push(res);
        }
    }

    if(s.size() != 1) return false;
    return true;
}

void testStack()
{
    int N, num; 
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        if(executeCase(num)) cout << s.top() << '\n';
        else cout << "ERROR" << '\n';
        while(!s.empty()) s.pop();
    }

    cout << '\n';
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string com;
    printf("%d\n", -12 % -11);

    while(true) 
    {
        getline(cin, com);
        
        if(com == "QUIT") break;
        else if(com == "END") {
            testStack();
            command.clear();
        }
        else command.push_back(com);
    }

    return 0;
}
