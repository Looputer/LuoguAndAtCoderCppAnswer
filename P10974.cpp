//
// Created by 陆熠辰 on 26-3-15.
//
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
typedef pair<int, int> pii;
vector<pii> edge[MaxN];
int deg[MaxN], dp[MaxN], n, t;

void dfs1(int u, int fa) {
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        if (deg[v] > 1) dp[u] += min(dp[v], w);
        else dp[u] += w;
    }
}

void dfs2(int u, int fa) {
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        if (deg[u] > 1) dp[v] +=  min(w, dp[u] - min(dp[v], w));
        else dp[v] += w;
        dfs2(v, u);
    }
}

void solve() {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++) edge[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(pii(v, w));
        edge[v].push_back(pii(u, w));
        deg[u]++;
        deg[v]++;
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int maxn = 0;
    for (int i = 1; i <= n; i++) maxn = max(maxn, dp[i]);
    cout << maxn << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}