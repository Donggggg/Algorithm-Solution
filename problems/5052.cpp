#include <iostream>
#include <algorithm>
using namespace std;

typedef struct _node {
    string data;
    _node* child[10];
    bool isPhone;
} Node;

int t, n;
Node* root;

void freeNode(Node* cur)
{
    for(int i = 0; i < 10; i++) {
        if(cur->child[i] != NULL) 
            freeNode(cur->child[i]);
    }
    free(cur);
}

Node* initNode() 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data.clear();
    node->isPhone = false;
    for(int i = 0; i < 10; i++)
        node->child[i] = NULL;
    return node;
}

bool pushString(string str)
{
    int pos = 0;
    Node* cur = root, *tmp;

    while(pos < str.length()) 
    {
        if (cur->child[str[pos] - '0'] == NULL) { // 자식노드가 없는 경우 노드 생성
            tmp = initNode();
            tmp->data = str.substr(0, pos+1);
            cur->child[str[pos] - '0'] = tmp;
        }

        cur = cur->child[str[pos] - '0'];

        if(cur->isPhone) // 존재하는 번호의 자식이 있는 경우 일관성 없음
            return false;

        pos++;
    }

    cur->isPhone = true; // 존재하는 번호로 체크

    return true;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> t;

    for(int i = 0; i < t; i++) {
        string list[10001];
        cin >> n;
        bool isRelated = true;
        root = initNode();
        
        for(int j = 0; j < n; j++) 
            cin >> list[j];
        
        sort(list, list+n, less<>());

        for(int j = 0; j < n; j++) {
            if(!pushString(list[j]))
                isRelated = false;
        }

        if(isRelated)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        freeNode(root); 
    }
    
    return 0;
}