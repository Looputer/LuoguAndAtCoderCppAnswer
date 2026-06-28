//
// Created by 陆熠辰 on 25-12-23.
//
#include <iostream>
#define int long long

using namespace std;

const int MaxN = 2e5+5;
int n, sum, mx = -1e18, f;
int mx_dp[MaxN],mn_dp[MaxN], a[MaxN];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        mx_dp[i] = -1e18;
        mx_dp[i] = 1e18;
        mx = max(mx, a[i]);
        if (a[i] > 0) f = 1;
    }
    if (f == 0) {
        cout << mx;
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        mx_dp[i] = max(a[i], mx_dp[i-1] + a[i]);
        mn_dp[i] = min(a[i], mn_dp[i-1] + a[i]);
    }
    int ans = -1e18;
    for (int i = 1; i <= n; i++) ans = max({ans, sum - mn_dp[i], mx_dp[i]});
    if (f == 1) {
        cout << ans;
    } else {
        cout << mx;
    }
    return 0;
}