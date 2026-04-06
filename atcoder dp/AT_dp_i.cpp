//
// Created by 陆熠辰 on 26-3-29.
//
#include <iomanip>
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 3005;
double p[MaxN], dp[MaxN][MaxN];
int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j < 1) dp[i][j] = (1 - p[i]) * dp[i-1][j];
            else dp[i][j] = p[i] * dp[i-1][j-1] + (1 - p[i]) * dp[i-1][j];
        }
    }
    double ans = 0;
    for (int j = 0; j <= n; j++) {
        if (j > n - j) ans += dp[n][j];
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}