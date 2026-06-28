//
// Created by 陆熠辰 on 26-3-15.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int dp[MaxN], a[MaxN], b[MaxN], suf[MaxN];
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = n; i >= 1; i--) {
        dp[i] = a[i];
        if (i + b[i] <= n)
            dp[i] = max(dp[i], a[i] + suf[i+b[i]]);
        if (b[i] == 0) 
            dp[i] = max(dp[i], a[i] + suf[i+1]);
        suf[i] = max(suf[i+1], dp[i]);
    }
    cout << suf[1];
    return 0;
}