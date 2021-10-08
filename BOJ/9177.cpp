#include <iostream>
#include <string>
#include <set>
#define WNUM 2
using namespace std;

int N;
string words[WNUM], comp;
int indexs[WNUM];

int isValidWord(char ch) {
    for(int i = 0; i < WNUM; i++)
        if(words[i][indexs[i]] == ch) return true;
    return false;
}

int decideComp(int depth) {
    char ch = comp[depth];
    if(depth == comp.length() - 1) {
        return isValidWord(ch);
    }

    for(int i = 0; i < WNUM; i++) {
        if(words[i][indexs[i]] == ch) {
            indexs[i]++;
            if(decideComp(depth + 1)) return true;
            indexs[i]--;
        }
    }
    return false;
}

int isError()
{
    set<char> set;
    for(int i = 0; i < WNUM; i++)
        for(int j = 0; j < words[i].length(); j++)
            set.insert(words[i][j]);
    for(int i = 0; i < comp.length(); i++)
        if(set.find(comp[i]) == set.end()) return true;
    return false;
}

int main()
{
    string answer;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> words[0] >> words[1] >> comp;
        if(isError()) answer = "no";
        else {
            fill(indexs, indexs+WNUM, 0);
            answer = decideComp(0) ? "yes" : "no" ;
        }
        cout << "Data set " << i << ": " << answer << '\n';
    }
    return 0;
}