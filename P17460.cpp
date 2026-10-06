//
// Created by 陆熠辰 on 2026/9/26.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 1e9;
int n;
string s;
int dp[2005][2005];

signed main() {
    cin >> n >> s;
    s = s + ' ';
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] += dp[i - 1][j];
            if (s[i] == '(') {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            if (s[j] == ')') {
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][0] % MOD << endl;
}