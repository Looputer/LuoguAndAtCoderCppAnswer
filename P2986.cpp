//
// Created by 陆熠辰 on 26-3-22.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
typedef pair<int, int> pii;
vector<pii> edge[MaxN];
int dp[MaxN], a[MaxN], sz[MaxN], n, m;

void dfs1(int u, int fa) {
    sz[u] = a[u];
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v] * w;
    }
}

void dfs2(int u, int fa, int w) {
    if (u != 1) dp[u] = dp[fa] - sz[u] * w * 2 + w * m;
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs2(v, u, w);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m += a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(v, w));
        edge[v].push_back(make_pair(u, w));
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    int ans = 1e18;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}