//
// Created by 陆熠辰 on 25-12-23.
//
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 1e4+5;
int n;
int a[MaxN], dp[MaxN][MaxN], c[MaxN];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j-1] + a[1];
            for (int k = 2; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][k-1] + a[k] + c[n - i + 1] - c[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}