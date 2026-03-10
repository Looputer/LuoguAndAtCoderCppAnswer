//
// Created by 陆熠辰 on 26-3-8.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

char a[505][505];
int dp[2][505][305];
int t, n, m, x;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> x;
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k <= x; k++) {
                    if (a[i][j] != '?')  dp[i & 1][j][k] = max(dp[i-1 & 1][j][k], dp[i & 1][j-1][k]) + a[i][j] - '0';
                    else {
                        if (k >= 1) dp[i & 1][j][k] = max(max(dp[i-1 & 1][j][k], dp[i & 1][j-1][k-1]) + 1, max(dp[i-1 & 1][j][k], dp[i & 1][j-1][k]));
                    }
                }
            }
        }
        int ans = -1e9;
        for (int i = 0; i <= x; i++) {
            ans = max(ans, dp[n & 1][m][i]);
        }
        cout << ans << '\n';
    }
}