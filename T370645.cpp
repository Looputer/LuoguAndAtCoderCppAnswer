//
// Created by 陆熠辰 on 26-1-11.
//
#include <iostream>
#include <string>
#define int long long
using namespace std;

const int MaxN = 1e3+5;
const int MOD = 1e9+7;
int n, l, r;
string s;
int dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> r;
    cin >> s;
    s = " " + s;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int len = 1, num = 0;
        for (int j = i; j >= 1 && i - j + 1 <= 18; j--) {
            num += (s[j] - '0') * len;
            len *= 10;
            if (num >= l && num <= r) {
                dp[i] += dp[j-1];
            }
            dp[i] %= MOD;
        }
    }
    cout << dp[n];
    return 0;
}