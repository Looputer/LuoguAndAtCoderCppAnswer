//
// Created by 陆熠辰 on 26-3-15.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
const int MOD = 1e9+7;
int n;
vector<int> edge[MaxN];
int dp[MaxN][2];

void dfs(int u, int fa) {
    dp[u][0] = dp[u][1] = 1;
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] *= dp[v][0] + dp[v][1];
        dp[u][0] %= MOD;
        dp[u][1] *= dp[v][0];
        dp[u][1] %= MOD;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
}