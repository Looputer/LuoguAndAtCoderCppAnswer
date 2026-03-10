//
// Created by 陆熠辰 on 26-3-8.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 6e3+5;
vector<int> vec[MaxN];
int dp[MaxN][2];
int a[MaxN];
int n;
void dfs(int u, int fa) {
    dp[u][1] = a[u];
    for (auto j : vec[u]) {
        if (j == fa) continue;
        dfs(j, u);
        dp[u][1] += dp[j][0];
        dp[u][0] += max(dp[j][1], dp[j][0]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}