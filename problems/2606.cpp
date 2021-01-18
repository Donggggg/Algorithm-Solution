#include <stdio.h>
#include <iostream>
#include <algorithm>

int arr[101][101], N, cnt = 0;

void infectComputer(int x)
{
    for(int y = 1; y <= N; y++) {
        if(arr[x][y] == 1) { 
            if(arr[y][y] == 0) // 아직 방문하지 않은 노드인 경우 감염 증가
                cnt++;
            arr[x][y] = 0;
            arr[y][x] = 0;
            arr[y][y] = -1;
            infectComputer(y);
        }
    }
}

int main()
{
    int pairNum, x, y;
    scanf("%d", &N);
    scanf("%d", &pairNum);
    for(int i = 0; i < pairNum; i++) {
        scanf("%d %d", &x, &y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    arr[1][1] = -1;

    infectComputer(1);
    printf("%d\n", cnt);

    return 0;
}