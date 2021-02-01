#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int N, K;
long double ans = 10000000000000000, arr[500];

long double getSTD(int start, int num)
{
    long double sum = 0, avg, davg, dsum = 0;

    for(int i = 0; i < num; i++)
        sum += arr[start+i];

    avg = sum / num;

    for(int i = 0; i < num; i++)
        dsum += (avg-arr[start+i]) * (avg-arr[start+i]);

    davg = dsum / num;

    return sqrt(davg);
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for(int i = 0; i < N; i++)
         cin >> arr[i];

    for(int pos = 0; pos < N-K+1; pos++) 
        for(int num = K; num <= N - pos; num++)
            ans = min(ans, getSTD(pos, num));
    
    
    cout << fixed << setprecision(11) << ans << endl;
    
    return 0;
}