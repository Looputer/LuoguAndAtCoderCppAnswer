//
// Created by 陆熠辰 on 26-1-18.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e6+5;
int n, k;
int a[55];
int dp[2][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j=0;j<MaxN;j++) dp[0][j] = dp[1][j] = k + 1;
    dp[0][0] = dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j=0;j<MaxN;j++) dp[i&1][j] = k + 1;
        for (int j = 0; j < MaxN; j++) {
            if (j - a[i] >= 0) dp[i & 1][j] = min(dp[i-1 & 1][j], dp[i & 1][j-a[i]] + 1);
            else dp[i & 1][j] = dp[i-1 & 1][j];
        }
    }
    for (int i = 1; i < MaxN; i++) {
        if (dp[n & 1][i] == 0 || dp[n & 1][i] > k) {
            cout << i - 1;
            break;
        }
    }
    return 0;
}