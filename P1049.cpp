//
// Created by 陆熠辰 on 26-1-22.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e4+5;
int v, n;
int a[35];
int dp[35][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - a[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - a[i]] + a[i]);
        }
    }
    cout << v - dp[n][v] << endl;
}