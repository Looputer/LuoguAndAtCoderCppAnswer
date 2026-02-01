//
// Created by 陆熠辰 on 26-2-1.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, m;
int map[105][105], dp[105][105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = map[i][j] = 1e13;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = w;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = dp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    int ans = 1e18;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                ans = min(ans, dp[i][j] + map[i][k] + map[k][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    if (ans > 1e12) cout << "No solution.";
    else cout << ans;
}