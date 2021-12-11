#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) answer.push_back(temp);
    return answer;
}

int main()
{
    int pos;
    string str;
    cin >> str;

    vector<string> list = split(str, ':');

    for(int i = 0; i < list.size(); i++) {
        if(list[i].length() != 4) {
            if(list[i].length() == 0) pos = i+1;
            int len = list[i].length();
            for(int j = 0; j < 4 - len; j++) 
                list[i] = "0" + list[i];
        }
    }

    while(list.size() < 8)
        list.insert(list.begin() + pos, "0000");

    if(list.size() > 8)
        list.erase(list.begin(), list.begin() + 1);

    str = "";
    for (int i = 0; i < list.size(); i++)
        str = str + ":" + list[i];

    cout << str.substr(1) << '\n';
    return 0;
}