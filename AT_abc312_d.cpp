//
// Created by 陆熠辰 on 2026/9/13.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 998244353;
string s;
int dp[3005][3005];

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int len = s.length();
    s = " " + s;
    dp[0][0] = 1;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == '(' && j != 0) dp[i][j] = dp[i-1][j-1];
            else if (s[i] == ')') dp[i][j] = dp[i-1][j+1];
            if (j == 0 && s[i] == '?') dp[i][j] = dp[i-1][j+1];
            else if (s[i] == '?') dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= MOD;
            //cout << dp[i][j] <<" ";
        }
        //cout << endl;
        //cout << dp[i][0] << endl;
    }
    cout << dp[len][0] % MOD;
}