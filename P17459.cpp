//
// Created by 陆熠辰 on 2026/9/26.
//
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

int n, m, S, T;
int degin[1005], degout[1005], flag[1005], vis[1005];
vector<int> edge[1005];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : edge[u]) {
        dfs(v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        degout[u]++;
        degin[v]++;
    }
    S = 0, T = n + 1;
    for (int i = 1; i <= n; i++) {
        if (degin[i] == 0) edge[S].push_back(i);
        if (degout[i] == 0) edge[i].push_back(T);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        vis[i] = 1;
        dfs(S);
        if (vis[T] == 0) ans++, flag[i] = 1;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if (flag[i]) cout << i << " ";
    }
}