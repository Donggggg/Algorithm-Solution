#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 100001

int N, K, temp;
bool visit[MAX+1]={0, };
pair<int,int> p, tempPair;
queue<pair<int,int>> q;

int main()
{
    scanf("%d %d", &N, &K);
    p.first = N;
    p.second = 0;

    q.push(p);

    while(1) {
        p = q.front(); q.pop();
        
        if(p.first == K) // 잡으면 종료
            break;

        p.second++; // 초 증가
        tempPair = p;

        if(p.first + 1 < MAX && !visit[p.first+1]) { // 걷기 (+1)
            tempPair.first = p.first + 1;
            q.push(tempPair);
            visit[tempPair.first] = true;
        }
        if(p.first - 1 >= 0 && !visit[p.first-1]) { // 걷기 (-1)
            tempPair.first = p.first - 1;
            q.push(tempPair);
            visit[tempPair.first] = true;
        }
        if(p.first * 2 < MAX && !visit[p.first*2]) { // 순간이동 (*2)
            tempPair.first = p.first * 2;
            q.push(tempPair);
            visit[tempPair.first] = true;
        }
    }

    printf("%d\n", p.second);

    return 0;
}