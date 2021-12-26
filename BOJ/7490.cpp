#include <iostream>
#include <string>
using namespace std;

int T, N;

void printExpression(int depth, int op, int num, int sum, string exp) {
    if(depth == N) {
        sum += op * num;

        if(sum == 0)
            cout << exp << '\n';

        return;
    }

    for(int i = 0; i < 3; i++) {
        switch (i)
        {
        case 0:
            printExpression(depth+1, op, num * 10 + depth + 1, sum, exp + " " + to_string(depth+1));
            break;
        case 1:
            printExpression(depth+1, 1, depth+1, sum + op * num, exp + "+" + to_string(depth+1));
            break;
        case 2:
            printExpression(depth+1, -1, depth+1, sum + op * num, exp + "-" + to_string(depth+1));
            break;
        }
    }

}

int main() {
    cin >> T;

    while(T--) {
        cin >> N;

        printExpression(1, 1, 1, 0, "1");
        
        cout << '\n';
    }

    return 0;
}