#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _node {
    string name;
    vector<struct _node> children;
} node;

int N;

bool nameCompare(node a, node b)
{
    return a.name < b.name;
}

int check(string str, node cur)
{
    for(int i = 0; i < cur.children.size(); i++) 
        if(!str.compare(cur.children[i].name))
            return i;
    return -1;
}

void printStructure(node cur, int depth)
{
    for(int i = 0; i < depth * 2; i++)
        cout << "-";
    cout << cur.name << "\n";

    // O(K * logK)
    sort(cur.children.begin(), cur.children.end(), nameCompare);

    for(int i = 0; i < cur.children.size(); i++)
        printStructure(cur.children[i], depth + 1);
}

int main()
{
    int n, pos;
    string str;
    node *cur, head, nd;
    vector<string> input_list;

    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;

    // O(N * K^2)
    while(N--)
    {
        input_list.clear();
        cin >> n;

        // O(K)
        for(int i = 0; i < n; i++) {
            cin >> str;
            input_list.push_back(str);
        }

        // 입구부터 탐색 시작
        cur = &head;
        // 현재 노드의 자식들 탐색 및 삽입 O(K^2)
        for(int i = 0; i < n; i++) {
            // 현재 노드의 자식 중 현재 먹이가 없는 경우 새로 추가 check 함수 : O(K)
            if((pos = check(input_list[i], *cur)) < 0) {
                node newNode;
                newNode.name = input_list[i];
                cur->children.push_back(newNode);
                pos = cur->children.size() - 1;
            }

            // 다음 노드로 이동
            cur = &(cur->children[pos]);
        }

    }

    // O(K * logK)
    sort(head.children.begin(), head.children.end(), nameCompare);

    // 최종 도식 출력 O(K * N)
    for(int i = 0; i < head.children.size(); i++)
        printStructure(head.children[i], 0);

    return 0;
}