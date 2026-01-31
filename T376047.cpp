//
// Created by 陆熠辰 on 26-1-16.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MaxN = 1e6+5;
string s;
int dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int n = s.length();
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i-1] != '0') dp[i] = dp[i-1];
        int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (val >= 10 && val <= 26) dp[i] += dp[i-2];
        dp[i] %= MOD;
    }
    cout << dp[n] << endl;
    return 0;
}