#include <iostream>
#include <vector>
#include <math.h>
#define MAX 4000000
using namespace std;
int N;

vector<int> getPrime(int n)
{
    vector<int> primes;
    int range = sqrt(n);
    int arr[MAX+1] = {0, };
    for(int i = 2; i <= range; i++) 
        if(!arr[i]) 
            for (int j = i*2; j <= N; j += i) arr[j] = 1;
    for(int i = 2; i <= N; i++) 
        if(!arr[i])
            primes.push_back(i);
    return primes;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    vector<int> primes = getPrime(N);
    int start, end, cur, cnt = 0;
    start = end = cur = 0;
    if(N > 1) {
        while(end <= primes.size()) {
            if(cur < N) {
                cur += primes[end++];
            } else if(cur == N) {
                cur -= primes[start++];
                cnt++;
            } else if(cur > N) {
                cur -= primes[start++];
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}