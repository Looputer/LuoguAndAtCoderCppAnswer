//
// Created by 陆熠辰 on 26-1-11.
//
#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 1e3+5;
const int MOD = 1e9+7;
int n, k;
string s;
int dp[MaxN][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int t = j - 1; t < i; t++) {
                string tmp = s.substr(t + 1, i - t);
                string rev = tmp;
                reverse(rev.begin(), rev.end());
                if (tmp == rev) {
                    dp[i][j] = dp[i][j] + dp[t][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[n][k];
    return 0;
}