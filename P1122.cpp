//
// Created by 陆熠辰 on 26-3-8.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e4+5;
vector<int> edge[MaxN];
int dp[MaxN], a[MaxN], n;
int ans = -1e18;

void dfs(int u, int fa) {
    dp[u] = a[u];
    for (int v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (dp[v] > 0) dp[u] += dp[v];
    }
    ans = max(ans, dp[u]);
}

bool cmp(int a, int b) {
    return a > b;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}