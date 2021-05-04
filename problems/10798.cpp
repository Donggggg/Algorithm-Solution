#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxLength = 0;
string arr[5], answer;
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        maxLength = max(maxLength, (int)arr[i].length());
    }

    for(int i = 0; i < maxLength; i++) {
        for(int j = 0; j < 5; j++) {
            if(arr[j][i] != '\0') {
                answer.push_back(arr[j][i]);
            }
        }
    }

    cout << answer << '\n';
    return 0;
}