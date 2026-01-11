//
// Created by 陆熠辰 on 26-1-2.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, h[MaxN], dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout << dp[n] << endl;
    return 0;
}