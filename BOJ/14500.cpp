#include <iostream>
#include <vector>
#include <utility>
#define MAX 500
#define TETRO_NUM 5
#define TETRO_LEN 3
#define SYM 2
#define TURN 4
#define ANTI 1
using namespace std;

int N, M;
int arr[MAX][MAX];
int maxNum = 0;
vector<pair<int, int> > tetrominos[TETRO_NUM];

void setTetromino()
{
    tetrominos[0].push_back(make_pair(1, 0));
    tetrominos[0].push_back(make_pair(2, 0));
    tetrominos[0].push_back(make_pair(3, 0));

    tetrominos[1].push_back(make_pair(1, 0));
    tetrominos[1].push_back(make_pair(0, 1));
    tetrominos[1].push_back(make_pair(1, 1));

    tetrominos[2].push_back(make_pair(0, 1));
    tetrominos[2].push_back(make_pair(0, 2));
    tetrominos[2].push_back(make_pair(1, 2));

    tetrominos[3].push_back(make_pair(0, 1));
    tetrominos[3].push_back(make_pair(1, 1));
    tetrominos[3].push_back(make_pair(1, 2));

    tetrominos[4].push_back(make_pair(1, 0));
    tetrominos[4].push_back(make_pair(2, 0));
    tetrominos[4].push_back(make_pair(1, 1));
}

int getSumOfZone(int i, int j, vector<pair<int,int>> tetro, int turn, int sym) 
{
    int s = (sym == ANTI) ? 1 : -1;

    for (; turn < TURN; turn++)
        for (int k = 0; k < TETRO_LEN; k++) {
            int x = tetro[k].first;
            int y = tetro[k].second;
            tetro[k] = make_pair(y, x * -1);
        }

    int sum = arr[i][j];

    for(int k = 0; k < TETRO_LEN; k++) {
        int nx = j + (tetro[k].first * s);
        int ny = i + tetro[k].second;

        if (nx < 0 || ny < 0 || N <= ny || M <= nx)
            return 0;

        sum += arr[ny][nx];
    }

    return sum;
}

void searchAllCase(int i, int j, int k)
{
    for (int sym = 0; sym < SYM; sym++)
        for (int turn = 0; turn < TURN; turn++)
            maxNum = max(maxNum, getSumOfZone(i, j, tetrominos[k], turn, sym));
}

void solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < TETRO_NUM; k++)
                searchAllCase(i, j, k);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    setTetromino();
    solve();

    cout << maxNum << '\n';
    return 0;
}