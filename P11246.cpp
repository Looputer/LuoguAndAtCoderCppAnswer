//
// Created by 陆熠辰 on 26-3-10.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int dp[MaxN], n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i * i <= n; i++) {
        for (int j = i * i; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }
    cout << dp[n] << endl;
}