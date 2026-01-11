//
// Created by 陆熠辰 on 26-1-6.
//
#include <iostream>
#include <cmath>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, k;
int a[MaxN];
int dp[MaxN];

int max(int a, int b) {
    return a > b ? a : b;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int m = max(1, i - k);
        for (int j = m; j < i; j++) {
            dp[i] = min(dp[i],  dp[j] + abs(a[i] - a[j]));
        }
    }
    cout << dp[n] << endl;
}