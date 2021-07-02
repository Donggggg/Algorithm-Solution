#include <iostream>
#include <utility>
using namespace std;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, x, y;
    int Case[5] = {0,};
    pair<int,int> pos;

    cin >> N;
    while(N--)
    {
        cin >> x >> y;
        pos = make_pair(x,y);

        if(pos.first > 0 && pos.second > 0)
            Case[0]++;
        else if(pos.first < 0 && pos.second > 0)
            Case[1]++;
        else if(pos.first < 0 && pos.second < 0)
            Case[2]++;
        else if(pos.first > 0 && pos.second < 0)
            Case[3]++;
        else
            Case[4]++;
    }

    cout << "Q1: " << Case[0] << '\n';
    cout << "Q2: " << Case[1] << '\n';
    cout << "Q3: " << Case[2] << '\n';
    cout << "Q4: " << Case[3] << '\n';
    cout << "AXIS: " << Case[4] << '\n';

    return 0;
}