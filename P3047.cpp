//
// Created by 陆熠辰 on 26-3-27.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, k;
int c[MaxN];
vector<int> edge[MaxN];
int dp[MaxN][25];

void dfs1(int u, int fa) {
    dp[u][0] = c[u];
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        for (int j = 1; j <= k; j++) {
            dp[u][j] += dp[v][j-1];
        }
    }
}

void dfs2(int u, int fa) {
    for (auto v : edge[u]) {
        if (v == fa) continue;
        for (int j = k; j >= 1; j--) {
            if (j >= 2) {
                dp[v][j] += dp[u][j-1] - dp[v][j-2];
            } else {
                dp[v][j] += dp[u][j-1];
            }
        }
        dfs2(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 0; j <= k; j++) {
            ans += dp[i][j];
        }
        cout << ans << '\n';
    }
    return 0;
}