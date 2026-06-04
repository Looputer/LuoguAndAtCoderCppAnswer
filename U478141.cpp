#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, a[1005], b[1005], dp[1005][1005];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i+n] = b[i];
    }
    for (int len = 3; len <= 2*n; len++) {
        for (int l = 1; l <= 2 * n; l++) {
            int r = l + len - 1;
            if (r > 2 * n) break;
            dp[l][r] = 1e18;
            for (int k = l + 1; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + a[k] + b[l] + b[r]);
            }
        }
    }
    int ans = 1e18;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = min(ans, dp[i][j] + dp[j][n+i]);
        }
    }
    cout << ans;
    return 0;
}