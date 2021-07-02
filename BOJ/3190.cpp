#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define APPLE 1
#define EAT 1
#define HUNGRY 0

int N, arr[101][101] ={0, };
int n, dir = 0, secs = 0, moveTurn = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char c;
vector<pair<int,int>> snake;
pair<int,char> moves[100];

void changeDirection(char turn)
{
    int change;

    switch (turn) {
        case 'D' :  
            change = 1;
            break;
        case 'L' :
            change = -1;
            break;
    }

    if((dir = (dir + change) % 4) < 0)
        dir = 3;
}

void moveSnake(int x, int y, int state)
{
    pair<int,int> end = snake.back(); // 꼬리 위치 잠시 저장

    for(int i = snake.size()-1; 0 < i; i--)  // 몸통 다 이동
        snake[i] = snake[i-1];

    if (state == EAT) // 사과 먹었으면 꼬리 위치 유지 및 길이 증가
        snake.push_back(end);

    snake[0] = make_pair(x, y); // 머리 이동
}

bool isSnakeDead(int x, int y)
{
    if(x > N || y > N || x < 1 || y < 1) // 벽에 박치기 갈기거나
        return true;

    for(int i = 0; i < snake.size(); i++) // 자기 몸에 부딪히면 사망
        if(snake[i].first == x && snake[i].second == y)
            return true;

    return false;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int x, y;
    cin >> N;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[x][y] = APPLE;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> c;
        moves[i] = make_pair(x,c);
    }

    snake.push_back(make_pair(1,1));
    
    while(1)
    {
        secs++;
        x = snake[0].first+dx[dir]; y = snake[0].second+dy[dir]; // 머리 위치

        if(isSnakeDead(x,y)) // 머리가 몸이나 벽에 부딪히는 경우
            break;
        
        if(arr[x][y] == APPLE) { // 사과를 먹으면 (개고생 1)사과 없애고 이동
            arr[x][y] = 0;
            moveSnake(x, y, EAT);
        }
        else // 못먹으면 그냥 이동
            moveSnake(x, y, HUNGRY);

        if(secs == moves[moveTurn].first) // 방향 전환 타이밍이면 방향 전환
            changeDirection(moves[moveTurn++].second);
    }

    cout << secs << '\n';

    return 0;
}