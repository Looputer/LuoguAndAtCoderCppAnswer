//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int MOD = 998244353;
const int MaxN = 5005;

int n, a[MaxN], dp[MaxN][MaxN], ans, multi[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 5000; j++) {
            if (j - a[i] >= 0) dp[i][j] = dp[i-1][j] + dp[i-1][j - a[i]];
            else dp[i][j] = dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
    multi[0] = 1;
    for (int i = 1; i <= n; i++) {
        multi[i] = multi[i-1] * 2 % MOD;
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j <= a[i]; j++) {
            sum += dp[i-1][j];
            sum %= MOD;
        }
        ans += (multi[i-1] - sum + MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
