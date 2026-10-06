//
// Created by 陆熠辰 on 26-1-22.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int m, dp[20][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= 17; i++) {
        // if (i * i * i * i > m) continue;
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - i * i * i * i >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - i * i * i * i] + 1);
        }
    }
    cout << dp[17][m] << endl;
    return 0;
}