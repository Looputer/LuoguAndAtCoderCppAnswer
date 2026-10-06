//
// Created by 陆熠辰 on 2026/10/5.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e18;
int n, k;
int a[505], dp[505][505];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            int mx = a[i];
            int mn = mx;
            for (int l = i; l >= j; l--) {
                mx = max(mx, a[l]);
                mn = min(mn, a[l]);
                dp[i][j] = max(dp[i][j], dp[l-1][j-1] + mx - mn);
            }
        }
    }
    cout << dp[n][k] << endl;
}