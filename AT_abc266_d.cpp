//
// Created by 陆熠辰 on 26-1-2.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n;
int dp[MaxN][5];
int t[MaxN], pos[MaxN], a[MaxN];
int add[MaxN][5];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> pos[i] >> a[i];
        add[t[i]][pos[i]] += a[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= t[n]; i++) {
        for (int j = 0;j < 5; j++) {
            dp[i][j] = dp[i-1][j];
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            if (j < 4) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
            dp[i][j] += add[i][j];
        }
    }
    int maxn = -1e9;
    for (int i = 0; i < 5;i++) {
        maxn = max(maxn, dp[t[n]][i]);
    }
    cout << maxn << '\n';
    return 0;
}