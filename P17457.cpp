//
// Created by 陆熠辰 on 2026/9/27.
//
#include <iostream>
#define int long long
using namespace std;

int n, a[2005], s[2005], dp[2005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i - 1], s[i] - s[j - 1] + dp[j]);
        }
    }
    cout << dp[n] << endl;
}