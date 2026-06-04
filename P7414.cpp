#include <iostream>
#include <cstring>
#define int long long
using namespace std;

string s;
int n, dp[55][55];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n) break;
            if (s[l] == s[r]) dp[l][r] = min(dp[l-1][r], dp[l][r-1]);
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}