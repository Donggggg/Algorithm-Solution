#include <iostream>
#define MAX 20000
using namespace std;

int N, S;
int list[MAX];

int main()
{
    int cnt = 0;

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> list[i];

    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++) 
            if(list[i] + list[j] <= S) cnt++;

    cout << cnt << '\n';
    
    return 0;
}