//
// Created by 陆熠辰 on 26-2-1.
//
#include <iostream>
#include <cstring>
#define int long long
#define endl "\n"
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
int dp[205][205];
int n, m, q, t[205];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u++; v++;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }
    cin >> q;
    int idx = 0;
    while (q--) {
        int x, y, ti;
        cin >> x >> y >> ti;
        x++; y++;
        if (t[x] > ti || t[y] > ti) {
            cout << -1 << endl;
            continue;
        }
        for (;idx < n && t[idx+1] <= ti;) {
            idx++;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][idx] + dp[idx][j]);
                }
            }
        }
        if (dp[x][y] == INF) cout << -1 << endl;
        else cout << dp[x][y] << endl;
    }
    return 0;
}