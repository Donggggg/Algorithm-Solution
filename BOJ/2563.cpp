#include <iostream>
using namespace std;

int N, x, y, w = 0;
bool paper[101][101] = {false,};

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;

    while(N--) {
        // 검은색 범위를 true로 마킹
        cin >> x >> y;
        for(int i = x; i < x+10; i++)
            for(int j = y; j < y+10; j++) 
                paper[i][j] = true;
    }
    
    // 모든 검은색 종이의 범위를 마킹한 후 너비 체크
    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++) 
            if(paper[i][j])
                w++;

    cout << w << '\n';
    return 0;
}