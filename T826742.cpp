//
// Created by 陆熠辰 on 2026/10/5.
//
#include <iostream>
#define int long long
using namespace std;

int n, prices[5005], dp[5005][3];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> prices[i];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i-1][2] - prices[i]);
        dp[i][1] = dp[i-1][0] + prices[i];
        dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
    }
    cout << max(dp[n][1], dp[n][2]) << endl;
}