//
// Created by 陆熠辰 on 26-1-18.
//
#include <iostream>
#define int long long
using namespace std;

int m, n;
int a[105];
int dp[105][10005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j - a[i] >= 0) dp[i][j] = dp[i - 1][j] + dp[i-1][j-a[i]];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}