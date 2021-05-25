#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <limits.h>

using namespace std;

set<string> gem_list;
set<string>::iterator iter;
vector<pair<string,int>> current;
vector<pair<int,int>> ans_list;

vector<int> solution(vector<string> gems) {
    int start, end;
    vector<int> answer;
    map<string,int> end_list;
    
    for(string gem : gems) 
        gem_list.insert(gem);
    
    start = end = 0;
    
    while(end < gems.size())
    {
        if(end_list.find(gems[end]) != end_list.end()) 
            end_list.find(gems[end])->second++;
        else
            end_list.insert(make_pair(gems[end], 1));
        
        end++;

        if(gem_list.size() == end_list.size()) {
            while(start != end)
            {
                end_list.find(gems[start])->second--;
                if(end_list.find(gems[start])->second == 0) {
                    end_list.erase(gems[start]);
                    ans_list.push_back(make_pair(start+1,end));
                    start++;
                    break;
                }
                start++;  
            }
        }
    }
       
    int r = INT_MAX;
    answer.assign(2,0);
    for(auto item : ans_list) {
        int dis = item.second - item.first;
        if(min(r,dis) != r) {
            answer[0] = item.first;
            answer[1] = item.second;
            r = dis;
        }
    }
    return answer;
}