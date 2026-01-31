//
// Created by 陆熠辰 on 26-1-22.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int m, dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        int s = i * i * i * i;
        if (s > m) break;
        for (int j = s; j <= m; j++) {
            dp[j] = min(dp[j], dp[j - s] + 1);
        }
    }
    cout << dp[m] << endl;
    return 0;
}