
/*
1. 모든 파티를 순회한다.
  1-1. 파티 내에 있는 인원들은 연결 상태로 만든다.
2. 진실을 아는 사람을 기준으로 그래프 탐색을 하여 같은 파티에 참여한 사람을 찾는다.
3. 모든 파티를 순회하며 진실을 아는 사람이 아무도 없는 파티만 카운트하여 출력한다.
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define MAX 50
using namespace std;

int N, M;
bool finalKnowns[MAX+1] = {false, };
vector<int> knowns;
vector<vector<int>> parties;
vector<set<int>> graph;

void linkPeople(vector<int> party) {
    for(int i = 0; i < party.size(); i++) {
        int person = party[i];

        for(int j = i + 1; j < party.size(); j++) {
            int target = party[j];

            if(graph[person].find(target) == graph[person].end()) 
                graph[person].insert(target);
            if(graph[target].find(person) == graph[target].end()) 
                graph[target].insert(person);
        }
    }
}

void findUnknowns() {
    queue<int> q;

    for(int i = 0; i < knowns.size(); i++) {
        q.push(knowns[i]);
        finalKnowns[knowns[i]] = true;

        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for(set<int>::iterator iter = graph[cur].begin(); iter != graph[cur].end(); iter++) {
                int next = *iter;

                if(finalKnowns[next]) continue;

                q.push(next);
                finalKnowns[next] = true;
            }
        }
    }
}

int countParty() {
    int cnt = 0;

    for(int i = 0; i < parties.size(); i++) {
        vector<int> party = parties[i];
        bool isValid = true;

        for(int j = 0; j < party.size(); j++) 
            if(finalKnowns[party[j]]) {
                isValid = false;
                break;
            }

        if(isValid) cnt++;
    }

    return cnt;
}

int main() {
    int num, x;

    cin >> N >> M;

    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> x;
        knowns.push_back(x);
    }

    for(int i = 0; i <= N; i++)
        graph.push_back(set<int>());

    for(int i = 0; i < M; i++) {
        cin >> num;
        vector<int> party;
        for(int j = 0; j < num; j++) {
            cin >> x;
            party.push_back(x);
        }
        parties.push_back(party);
        linkPeople(party);
    }

    findUnknowns();

    cout << countParty() << '\n';

    return 0;
}