//
// Created by 陆熠辰 on 2026/10/4.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5, INF = 0x3f3f3f3f3f3f3f3f;
int n, a[MaxN], dp[MaxN][3];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
            dp[i][1] = dp[i][2] = INF;
        } else if (a[i] == 1) {
            dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
            dp[i][1] = min({dp[i-1][0], dp[i-1][2]});
            dp[i][2] = INF;
        } else if (a[i] == 2) {
            dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
            dp[i][1] = INF;
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        } else {
            dp[i][0] = INF;
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]});
}