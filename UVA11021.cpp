//
// Created by 陆熠辰 on 26-4-5.
//
#include <iomanip>
#include <iostream>
#define int long long
using namespace std;

int t, n, k, m;
double p[1005], dp[1005];

void solve(int num) {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        double sum = 0.0;
        double dp_prev = dp[i-1];
        for (int j = 1; j <= n; j++) {
            sum += p[j] * pow(dp_prev, j);
        }
        dp[i] = sum;
    }
    double ans = pow(dp[m], k);
    cout << "Case #" << n << ": " << fixed << setprecision(10) << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve(t);
    }
    return 0;
}