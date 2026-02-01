//
// Created by 陆熠辰 on 26-2-1.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, m, cnt;
int dp[305][305], map[305][305];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        map[u][v] = dp[u][v] = min(dp[u][v], w);
        map[v][u] = dp[v][u] = min(dp[v][u], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] < map[i][j]) {
                cnt++;
            }
        }
    }
    cout << cnt / 2 << endl;
}