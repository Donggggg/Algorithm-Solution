#include <iostream>
#include <vector>
using namespace std;

vector<string> list;

bool popString(string str)
{
    int i, pos = 0, start, size;
    string new_str;

    while(pos < str.length())
    {
        new_str.clear();

        if(str[pos] == str[pos+1]) { // 연속문자열인 경우
            for(i = pos+2; i < str.length(); i++) 
                if(str[pos] != str[i])
                    break;

            // 뽑을 부분 세팅
            start = pos;
            size = i - pos;

            // 뽑기
            new_str.append(str.substr(0, start));
            new_str.append(str.substr(start+size, str.length()));

            if(new_str.length() == 0) // 뽑고 나서 문자열이 남아있지 않으면 true 리턴
                return true;

            list.push_back(new_str); // 리스트에 삽입
            pos += size;
        } else {
            pos++;
        }
    }
    return false;
}

int main()
{
    int T;
    bool isCorrect;
    string str;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        list.clear();
        cin >> str;
        isCorrect = false;
        list.push_back(str);
        for(int i = 0; i < list.size(); i++) { 
            if(popString(list[i])) { 
                cout << "1" << '\n';
                isCorrect = true;
                break;
            }
        }
        if(!isCorrect)
            cout << "0" << '\n';
    }    


    return 0;
}