//
// Created by 陆熠辰 on 25-12-23.
//
#include <iostream>
#define int long long

using namespace std;

const int MaxN = 2e5+5;
int n;
int dp[MaxN], a[MaxN];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i]) break;
        dp[i] = max(dp[i-1], dp[i-1]+a[i]);
        cout << dp[i] << " ";
        if (n == 1 && dp[1] == 0) i = 1;
    }
    cout << dp[n] << endl;
    return 0;
}