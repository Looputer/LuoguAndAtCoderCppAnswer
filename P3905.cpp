//
// Created by 陆熠辰 on 26-2-1.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1005;
int n, m, d;
int dp[MaxN][MaxN], flag[MaxN][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }
    cin >> d;
    for (int i = 1; i <= d; i++) {
        int u, v;
        cin >> u >> v;
        flag[u][v] = flag[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (flag[i][j]) continue;
            if (dp[i][j] < 0x3f3f3f3f3f3f3f3f) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << endl;
    return 0;
}