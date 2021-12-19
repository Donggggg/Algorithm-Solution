#include <iostream>
#include <string>
using namespace std;

string convert(int x) {
    string result = "";

    do {
        int binary = x % 2;
        result = to_string(binary) + result;
        x /= 2;
    }
    while (0 < x);

    return result;
}

int main() {
    int x;

    scanf("%o", &x);

    printf("%s\n", convert(x).c_str());

    return 0;
}