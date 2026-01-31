//
// Created by 陆熠辰 on 26-1-18.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e7+5;
int t, m;
int a[MaxN], b[MaxN];
int dp[2][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= t; j++) {
            if (j - a[i] >= 0) dp[i & 1][j] = max(dp[i-1 & 1][j], dp[i & 1][j-a[i]] + b[i]);
            else dp[i & 1][j] = dp[i-1 & 1][j];
        }
    }
    cout << dp[m & 1][t] << endl;
}