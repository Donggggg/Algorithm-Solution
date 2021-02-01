#include <iostream>
#include <vector>

using namespace std;

int N, K, level, mx = 0;
char c;
vector<string> arr;
vector<char> known, list;
int mark[26];
string str;

int getWordNumber()
{
    int num = 0;
    bool isExist, isKnow;

    for(int i = 0; i < N; i++) { // 모든 단어 확인
        isKnow = true;

        for(int j = 4; j < arr[i].length()-4; j++) { // 앞 4자리(anta), 뒤 4자리(tica) 제외하고 검사
            isExist = false;

            for(int k = 0; k < list.size(); k++) { // 배운 알파벳 리스트
                if(list[k] == arr[i][j]) { 
                    isExist = true;
                    break;
                }
            }

            if(!isExist) { // 배운 알파벳이 아니라면 모른다.
                isKnow = false;
                break;
            }
        }
        if(isKnow)  // 아는 단어면 추가
            num++;
    }

    return num;
}

bool isPromising(int c, int length) // 현재 배운 알파벳 리스트에 해당 알파벳이 있는지 검사
{
    for(int i = 0; i < length; i++)
        if(c == list[i])
            return false;
    return true;
}

void learnCharacter(int idx, int length)
{
    if(length == level) { // 배울 수 있는 알파벳 개수가 다 찬 경우
        mx = max(mx, getWordNumber()); // 단어 개수 셈
        return ;
    }
    
    for(int i = idx; i < known.size()-5; i++) { // 모든 가능성 있는 알파벳 탐색
        if(isPromising(known[i], length)) { // 현재 배운 알파벳 리스트에 없다면 추가
            list[length] = known[i];
            learnCharacter(i+1, length+1);
        }
    }
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    if(K < 5) { // 알 수 있는 알파벳이 5개 미만이면 아무것도 못배움..
        cout << '0' << "\n";
        return 0;
    }
    list.assign(K-5,0);
    for(int i = 0; i < N; i++) {
        cin >> str;
        arr.push_back(str);
    }
    
    // 모든 단어에 있는 알파벳 검사
    for(int i = 0; i < N; i++) 
        for(int j = 4; j < arr[i].length()-4; j++) 
            mark[arr[i][j] - 'a']++;
     mark['a'-'a'] = mark['c'-'a'] = mark['n'-'a'] = mark['i'-'a'] = mark['t'-'a'] = 0;

    // 배울 가능성 있는 알파벳을 저장
    for(int i = 0; i < 26; i++) 
        if(mark[i]) 
            known.push_back('a'+i);

    // known : 배울 가능성이 있는 알파벳 // list : 배운 알파벳
    known.push_back('a'); list.push_back('a');
    known.push_back('c'); list.push_back('c');
    known.push_back('n'); list.push_back('n');
    known.push_back('t'); list.push_back('t');
    known.push_back('i'); list.push_back('i');
    
    level = K - 5; // 배울 수 있는 알파벳 개수

    if(known.size() < K)  // 배울 수 있는 알파벳 개수가 모든 단어에 있는 알파벳 개수보다 많으면 모든 단어를 배움
        mx = N;
    else  // 그렇지 않다면 배울 수 있는 단어 수 탐색
        learnCharacter(0,0);
    
    cout << mx << "\n";

    return 0;
}