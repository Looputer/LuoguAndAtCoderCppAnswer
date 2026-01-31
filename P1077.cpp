//
// Created by 陆熠辰 on 26-1-11.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 1e6+7;
int n, m;
int a[105], dp[105][105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= a[j]; k++) {
                if (k > i) break;
                dp[i][j] += dp[i - k][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[m][n] << '\n';
    return 0;
}