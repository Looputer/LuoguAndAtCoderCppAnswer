//
// Created by 陆熠辰 on 26-1-18.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e4+5;
int m, n;
int p[MaxN], t[MaxN], dp[2][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j - t[i] >= 0) dp[i & 1][j] = max(dp[i - 1 & 1][j], dp[i & 1][j - t[i]] + p[i]);
            else dp[i & 1][j] = dp[i - 1 & 1][j];
        }
    }
    cout << dp[n & 1][m] << endl;
    return 0;
}