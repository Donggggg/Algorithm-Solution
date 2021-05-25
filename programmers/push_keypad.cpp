#include <string>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int pos = 1;
    pair<int,int> rightHand, leftHand, keypad[10];
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++) 
            keypad[pos++] = make_pair(i-1, j-1);

    keypad[0] = make_pair(3,1);
    rightHand = make_pair(3,2);
    leftHand = make_pair(3,0);

    for(int i = 0; i < numbers.size(); i++) {
        int cur = numbers[i];
        if(cur == 1 || cur == 4 || cur == 7) {
            answer.push_back('L');
            leftHand = keypad[cur];
        } else if(cur == 3 || cur == 6 || cur == 9) {
            answer.push_back('R');
            rightHand = keypad[cur];
        } else {
            int leftDis, rightDis;
            leftDis = abs(leftHand.first - keypad[cur].first) 
                + abs(leftHand.second - keypad[cur].second);
            rightDis = abs(rightHand.first - keypad[cur].first) 
                + abs(rightHand.second - keypad[cur].second);

            if(leftDis > rightDis) {
                answer.push_back('R');
                rightHand = keypad[cur];
            } else if (leftDis < rightDis) {
                answer.push_back('L');
                leftHand = keypad[cur];
            } else if (leftDis == rightDis) {
                answer.push_back((char)(hand[0]-32));
                switch(hand[0]) {
                    case 'r' :
                        rightHand = keypad[cur];
                        break;
                    case 'l' :
                        leftHand = keypad[cur];
                        break;
                }
            }
        }
    }

    return answer;
}