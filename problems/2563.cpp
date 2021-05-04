#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int arr[100] = { 0, };
    int sq[100][100] = { 0, };
    int n = 0;
    int a=0,b=0;
    int s=0;
    cin >> n;
    for (int i = 0; i < n*2; i++) {
        cin >> arr[i];
    }

    for (int k = 0; k < n*2; k+=2) {
        b = arr[k+1] + 10;
        a = arr[k] + 10;
        for (int i = arr[k]; i < a; i++) {
            for (int j = arr[k+1]; j < b; j++) {
                if (sq[i][j] != 1) {
                    sq[i][j] = 1;
                    s++;
                }
            }
        }
    }
    
    cout << s;


    return 0;
}