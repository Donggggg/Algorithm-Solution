#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct apart{
    int location;
    int number;
} Apart;

bool compare(Apart a, Apart b) { return a.location < b.location; }

int main()
{
    int N, K, S;
    int start, end, seatNum, now;
    long long ans = 0;
    vector<Apart> arr;
    Apart temp;

    scanf("%d %d %d", &N, &K, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &temp.location, &temp.number);
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), compare); // ㅈㄴ 어이없는 문제인지 내가 생각해줘야되는지 모르겠음;;

    start = 0;
    end = N - 1;

    while (start <= end) {
        seatNum = K;

        if (arr[start].location < S) { // start 포인터가 학교를 지나지 않은 경우
            now = start;
            ans += 2 * (S - arr[start].location);

            while (arr[start].location < S && seatNum) { // 버스가 꽉 찰 때까지 태우기
                if (arr[now].number <= seatNum) { // 해당 아파트의 인원이 전원 탑승 가능한 경우
                    seatNum -= arr[now].number;
                    now++;
                }
                else { // 해당 아파트의 인원이 전원 탑승하지 못하는 경우
                    arr[now].number -= seatNum;
                    seatNum = 0;
                }
                start = now;
            }
        }
        else { // end 포인터가 학교를 지나지 않은 경우
            now = end;
            ans += 2 * (arr[end].location - S);

            while (S < arr[end].location && seatNum) { // 버스가 꽉 찰 때까지 태우기
                if (arr[now].number <= seatNum) { // 해당 아파트의 인원이 전원 탑승 가능한 경우
                    seatNum -= arr[now].number;
                    now--;
                }
                else { // 해당 아파트의 인원이 전원 탑승하지 못하는 경우
                    arr[now].number -= seatNum;
                    seatNum = 0;
                }
            }
            end = now;
        }
    }

    printf("%lld\n", ans);

    return 0;
}