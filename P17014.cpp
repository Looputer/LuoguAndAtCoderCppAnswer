#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
vector<int> edge[MaxN];
int col[MaxN], ans = 2;
int t, n;

void dfs(int u, int c) {
    col[u] = c;
    for (auto v : edge[u]) {
        if (col[v] == 0) dfs(v, 3 - c);
        else if (col[v] == col[u]) ans = 3;
    }
}

