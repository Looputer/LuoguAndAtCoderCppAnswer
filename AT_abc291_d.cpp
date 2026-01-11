//
// Created by 陆熠辰 on 26-1-2.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 998244353;
const int MaxN = 2e5+5;
int n;
int a[MaxN], b[MaxN];
int dp[MaxN][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][0] * (a[i-1] != a[i]);
        dp[i][0] += dp[i-1][1] * (b[i-1] != a[i]);
        dp[i][0] %= MOD;
        dp[i][1] = dp[i-1][0] * (a[i-1] != b[i]);
        dp[i][1] += dp[i-1][1] * (b[i-1] != b[i]);
        dp[i][1] %= MOD;
    }
    int ans = dp[n][1] + dp[n][0];
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}