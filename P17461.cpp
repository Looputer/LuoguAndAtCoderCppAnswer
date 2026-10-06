//
// Created by 陆熠辰 on 2026/9/27.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
const int MOD = 998244353;
int n, m, vis[MaxN];
int ans = 1;
vector<int> edge[MaxN];

void dfs(int u, int idx, int fa) {
    vis[u] = idx;
    for (auto v : edge[u]) {
        if (v == fa) continue;
        if (vis[v]) {
            if (vis[v] < vis[u]) continue;
            ans *= vis[v] - vis[u] + 1;
            ans %= MOD;
            //cout << u << "->" << v << " " << vis[u] << "->" << vis[v] << endl;
            continue;
        }
        dfs(v, idx + 1, u);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 1, -1);
    cout << ans << endl;
}