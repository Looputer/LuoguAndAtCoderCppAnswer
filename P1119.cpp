//
// Created by 陆熠辰 on 26-2-1.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int map[205][205], dp[205][205];
int n, m, q, t[205];

void floyd(int t) {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1;i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int k = 1; k <= t; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    memset(map, 0x3f, sizeof(map));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        map[u][v] = min(map[u][v], w);
        map[v][u] = min(map[v][u], w);
    }
    cin >> q;
    while (q--) {
        int x, y, t;
        cin >> x >> y >> t;
        floyd(t);
        cout << dp[x][y] << endl;
    }
    return 0;
}