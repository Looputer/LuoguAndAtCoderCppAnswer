//
// Created by 陆熠辰 on 26-1-1.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, m, vis[MaxN];
vector<int> vec[MaxN];

void dfs(int u, int n) {
    if (vis[u]) return;
    vis[u] = n;
    for (auto v : vec[u]) {
        dfs(v, n);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        vec[v].push_back(u);
    }
    for (int i = n; i ; i--) dfs(i, i);
    for (int i = 1; i <= n; i++) cout << vis[i] << " ";
    cout << endl;
}