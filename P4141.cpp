//
// Created by 陆熠辰 on 26-1-31.
//
#include <iostream>
#define int long long
using namespace std;

int n, m, a[2005], dp[2][2005];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    dp[0][0] = dp[1][0]= 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i]; j--) {
            dp[0][j] += dp[0][j - a[i]];
            dp[0][j] %= 10;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j - a[i] >= 0) dp[1][j] = dp[0][j] - dp[1][j - a[i]] + 10;
            else dp[1][j] = dp[0][j];
            dp[1][j] %= 10;
            cout << dp[1][j];
        }
        cout << endl;
    }
    return 0;
}