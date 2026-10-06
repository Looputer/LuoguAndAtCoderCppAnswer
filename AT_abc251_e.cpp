//
// Created by 陆熠辰 on 2026/10/4.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 3e5+5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, a[MaxN], dp[MaxN][2];

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    int ans = 1e18;
    //if feed 1
    dp[1][0] = INF;
    dp[1][1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i][0] ,dp[i-1][1]);
        dp[i][1] = a[i] + min(dp[i-1][0], dp[i-1][1]);
    }
    ans = min(dp[n][0], dp[n][1]);
    //if not feed 1
    dp[1][0] = 0;
    dp[1][1] = INF;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i][0] , dp[i-1][1]);
        dp[i][1] = a[i] + min(dp[i-1][0], dp[i-1][1]);
    }
    ans = min(ans, dp[n][1]);
    cout << ans << endl;
}