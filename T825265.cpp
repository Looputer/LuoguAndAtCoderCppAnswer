//
// Created by 陆熠辰 on 2026/10/4.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 205;
int n, t[MaxN], w[MaxN];
//int dp[205][205][205];
int dp[MaxN][MaxN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> w[i];
    /*/
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= 200; k++) {
                if (k >= w[i])
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - w[i]]);
                if (j >= t[i])
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - t[i]][k]);
                // if (i == 2 && j == 1 && k == 3) cout << "???";
            }
        }
    }
    //cout << dp[1][1][0] << " " << dp[2][1][3] << " " << dp[5][5][4] << endl;
    for (int j = 0; j <= 200; j++) {
        for (int k = 0; k <= j; k++) {
            if (dp[n][j][k] ) {
                cout << j << endl;
                exit(0);
            }
        }
    }
    /*/
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 200; j++) {
            dp[i][j] = dp[i-1][j] + w[i];
            if (j >= t[i]) dp[i][j] = min(dp[i][j], dp[i-1][j-t[i]]);
        }
    }
    int minn = 1e18;
    for (int i = 0; i <= 200; i++) {
        if (dp[n][i] == 0) continue;
        minn = min(minn, dp[n][i]);
    }
    cout << minn << endl;
}