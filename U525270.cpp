//
// Created by 陆熠辰 on 26-1-6.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n;
int a[MaxN], b[MaxN], dp[MaxN][3];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][1], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}