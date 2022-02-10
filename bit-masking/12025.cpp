#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

long long N;
vector<int> wrongIndexes;

string getConfusedPassword(string pswd) {
    string target = pswd;
    int idx = target.size() - 1;

    for(int i = target.size() - 1; 0 <= i; i--) {
        if(target[i] == '7' || target[i] == '6') {
            wrongIndexes.push_back(i);
            target[i] -= 5;
        }
        else if(target[i] == '2' || target[i] == '1') {
             wrongIndexes.push_back(i);
        }
    }

    return target;
}

string getValidatePassword(string pswd, long long n) {
    int idx = 0;

    while(n) {
        if(n % 2) pswd[wrongIndexes[idx]] += 5;
        n >>= 1;
        idx++;
    }

    return pswd;
}

int main() {
    string password, confusedPassword;

    cin >> password;
    cin >> N;

    confusedPassword = getConfusedPassword(password);
    if(N < 1 || (long long)pow(2, wrongIndexes.size()) < N) cout << -1 << '\n';
    else cout << getValidatePassword(confusedPassword, N - 1) << '\n';

    return 0;
} 