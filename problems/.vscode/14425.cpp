#include <iostream>
#include <map>
using namespace std;
string test[10000];
map<string, string> set;

int N, M, cnt = 0;
string tmp;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        set[tmp] = tmp;
    }

    for(int i = 0; i < M; i++)
        cin >> test[i];

    for(int i = 0; i < M; i++) 
        if(!set.find(test[i])->first.compare(test[i])) 
            cnt++;
  
    cout << cnt << "\n";

    return 0;
}
