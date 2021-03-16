#include <iostream>

using namespace std;

int N, M, graph[200][200], plan[2000];
int group[200][200];

void makeGroup()
{
    for(int i = 0)
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N; 
    cin >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> graph[i][j];
    for(int i = 0; i < M; i++)
        cin >> plan[i];

    makeGroup();
    
    
    return 0;
}