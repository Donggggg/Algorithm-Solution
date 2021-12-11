#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 5001
#define INF 1e6
using namespace std;

int N;

int main()
{
    int x, y, left, right, sum = 0;
    vector<int> firsts;
    vector<int> seconds;
    vector<int> list[MAX];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        list[y].push_back(x);
    }
    for (int i = 1; i <= N; i++)
        sort(list[i].begin(), list[i].end());

    for(int i = 1 ; i <= N; i++)
        for (int j = 0; j < list[i].size(); j++) {
            left = j == 0 ? INF : list[i][j] - list[i][j - 1];
            right = j == list[i].size() - 1 ? INF : list[i][j + 1] - list[i][j];
            sum += min(left, right);
        }

    cout << sum << '\n';

    return 0;
}