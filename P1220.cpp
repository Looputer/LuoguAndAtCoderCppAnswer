#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, m, a[105], b[105], dp[105][105][2], s[105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n ; i++) {
        cin >> a[i] >> b[i];
        s[i] = s[i-1] + b[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[m][m][0] = dp[m][m][1] = 0;

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n) break;
            dp[l][r][0] = min(dp[l][r][0], dp[l+1][r][0] + (a[l+1] - a[l]) * (s[l] + s[n] - s[r]));
            dp[l][r][0] = min(dp[l][r][0], dp[l+1][r][1] + (a[r] - a[l]) * (s[l] + s[n] - s[r]));
            dp[l][r][1] = min(dp[l][r][1], dp[l][r-1][0] + (a[r] - a[l]) * (s[l-1] + s[n] - s[r-1]));
            dp[l][r][1] = min(dp[l][r][1], dp[l][r-1][1] + (a[r] - a[r-1]) * (s[l-1] + s[n] - s[r-1]));
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]);
}
