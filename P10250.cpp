//
// Created by 陆熠辰 on 26-3-13.
//
#include <iostream>
#define int long long
using namespace std;

int n, dp[65];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i < n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout << dp[n - 1];
    return 0;
}