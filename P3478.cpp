//
// Created by 陆熠辰 on 26-3-22.
//
//#pragma GCC optimize(2)
#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int MaxN = 1e6+5;
vector<int> edge[MaxN];
int n, dp[MaxN], sz[MaxN];

void dfs1(int u, int fa) {
    sz[u] = 1;
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v];
    }
}

void dfs2(int u, int fa) {
    if (u != 1) dp[u] = n - 2 * sz[u] + dp[fa];
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs2(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int ans = -1, maxi = -1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > maxi) {
            ans = i;
            maxi = dp[i];
        }
    }
    cout << ans << '\n';
    return 0;
}