//
// Created by 陆熠辰 on 25-12-21.
//
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
int dp[MaxN];
vector<pair<int, int>> vec[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[v].push_back({u, w});
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [j, w] : vec[i]) {
            dp[i] = min(dp[i], dp[j] + w);
        }
    }
    if (dp[n] == INF) cout << -1 << endl;
    else cout << dp[n] << endl;
    return 0;
}