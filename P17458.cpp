//
// Created by 陆熠辰 on 2026/9/27.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e4+5;
int n, sz[MaxN];
vector<int> edge[MaxN];

void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, -1);
    int minn = 1e9;
    for (int i = 1; i <= n; i++) {
        int minus = abs(2 * sz[i] - n);
        minn = min(minn, minus);
    }
    cout << minn << endl;
}