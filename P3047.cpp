//
// Created by 陆熠辰 on 26-3-27.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, k;
int a[MaxN];
vector<int> edge[MaxN];
int dp[MaxN][25];

void dfs1(int u, int fa) {
    dp[u][0] = a[u];
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        for (int i = 1; i <= k; i++) {
            dp[u][i] += dp[v][i-1];
        }
    }
}

void dfs2(int u, int fa) {
    for (auto v : edge[u]) {
        if (v == fa) continue;
        for (int i = k; i >= 2; i--) {
            dp[v][i] += dp[u][i-1] - dp[v][i-2];
        }
        dp[v][1] += dp[u][0];
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
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j <= k; j++) {
            sum += dp[i][j];
        }
        cout << sum << endl;
    }
    return 0;
}