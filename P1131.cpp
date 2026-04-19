//
// Created by 陆熠辰 on 26-4-10.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 5e5+5;
vector<pair<int, int> > edge[MaxN];
int dp[MaxN], ans, n, s;

void dfs(int u, int fa) {
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v]+w);
    }
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        ans += dp[u] - (dp[v] + w);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dfs(s, 0);
    cout << ans << '\n';
    return 0;
}