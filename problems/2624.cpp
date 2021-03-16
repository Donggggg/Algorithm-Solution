#include <iostream>
#include <vector>
using namespace std;

int N, M, num, n;
vector<int> pd[1000];
int check[101] = {0, };
bool poped[101] = {false, };

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;

   for(int i = 0; i < M; i++) {
       cin >> num;
       for(int j = 0; j < num; j++) {
           cin >> n;
           pd[i].push_back(n);
           if(j != 0)
            check[n]++;
       }
   }

   while(1) {
       for(int i = 0; i < M; i++) {
           int x = pd[i].front();
           if(check[x] == 0) {
               if(!poped[x]) {
                pd[i].erase(pd[i].begin());
                poped[x] = true;
                cout << x << '\n';
               }
           }
       }
   }
    return 0;
}