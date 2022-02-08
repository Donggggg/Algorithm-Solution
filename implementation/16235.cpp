#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10
#define DIRS 8
#define ENERGEY_DEFAULT 5

struct Tree {
    int r;
    int c;
    int year;
};

int N, M, K, A[MAX+1][MAX+1], field[MAX+1][MAX+1];
vector<Tree> trees, nextTrees;
vector<Tree>::iterator iter;

bool comapreTree(Tree t1, Tree t2) {
    return t1.year < t2.year;
}

void grow() {    
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for(iter = trees.begin(); iter != trees.end(); iter++) {
        Tree tree = *iter;
        
        if(field[tree.r][tree.c] < tree.year) {
            iter->year = -(iter->year);
            continue;
        }

        field[tree.r][tree.c] -= tree.year;
        iter->year++;

        if(iter->year % 5 == 0) {
            for(int d = 0; d < DIRS; d++) {
                int nr = tree.r + dr[d];
                int nc = tree.c + dc[d];

                if (nr < 1 || nc < 1 || N < nr || N < nc)
                    continue;

                nextTrees.push_back({nr, nc, 1});
            }
        }
    }

}

void rot() {
    for(int i = 0; i < trees.size(); i++) {
        Tree tree = trees[i];
        if(tree.year < 0) field[tree.r][tree.c] += (-tree.year) / 2;
        else nextTrees.push_back(tree);
    }

    trees = nextTrees;
}

void provide() {
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            field[i][j] += A[i][j];
}

void solve() {
    while(K--) {
        nextTrees.clear();
        grow();
        rot();
        provide();
    }
   
    cout << trees.size() << '\n';
}

int main() {
    int x, y, e;
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++) {
            cin >> A[i][j];
            field[i][j] = ENERGEY_DEFAULT;
        }
    
    for(int i = 0; i < M; i++) {
        cin >> x >> y >> e;
        trees.push_back({x,y,e});
    }

    sort(trees.begin(), trees.end(), comapreTree);

    solve();

    return 0;
}