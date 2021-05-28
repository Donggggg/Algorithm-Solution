#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<vector<int>> mappings;
set<set<int>> results;

bool checkValid(string b, string u)
{
    if(b.length() != u.length())
        return false;
    
    for(int i = 0; i < b.length(); i++)
        if(b[i] != u[i] && b[i] != '*')
            return false;
    
    return true;
}

void pushResult(vector<int> list)
{
    set<int> tmp;
    for(auto item : list)
        tmp.insert(item);
    results.insert(tmp);
}

void dfs(int depth, vector<int> list)
{
    if(depth == mappings.size()) {
        // for(auto item : list) {
        //     printf("%d ", item);
        // }
        // printf("\n");
        
        pushResult(list);
        return ;
    }
    
    for(int i = 0; i < mappings[depth].size(); i++) {
        if(find(list.begin(), list.end(), mappings[depth][i]) 
           != list.end()) continue;
        list.push_back(mappings[depth][i]);
        dfs(depth+1, list);
        list.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<int> list;

    for(int i = 0; i < banned_id.size(); i++) {
        list.clear();
        for(int j = 0; j < user_id.size(); j++) {
            if(checkValid(banned_id[i], user_id[j])) {
                list.push_back(j);
            }
        }
        mappings.push_back(list);
    }
    
    list.clear();
    dfs(0, list);
    
    answer = results.size();
    
    return answer;
}