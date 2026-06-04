//
// Created by 陆熠辰 on 26-3-15.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int dp[MaxN], a[MaxN], b[MaxN];
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], dp[i] = a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        if (i + b[i] <= n)
            dp[i + b[i]] = max(dp[i + b[i]], dp[i] + a[i + b[i]]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << dp[n] << endl;
    return 0;
}