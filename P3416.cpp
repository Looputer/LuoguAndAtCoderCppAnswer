#include <iostream>
#define int long long
using namespace std;

int n, dp[250][250], ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][i];
        ans = max(ans, dp[i][i]);
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n) break;
            for (int k = l; k < r; k++) {
                if (dp[l][k] == dp[k+1][r] && dp[l][k] != 0) dp[l][r] = max(dp[l][r], dp[l][k] + 1);
                ans = max(ans, dp[l][r]);
            }
        }
    }
    cout << ans << endl;
}