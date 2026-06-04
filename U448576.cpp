#include <iostream>
#include <numeric>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
int n, a[205], dp[205][205], g[1005][1005], T;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= 2*n; i++) {
        for (int j = 1 ; j <= 2 * n; j++) {
            g[i][j] = gcd(a[i], a[j]);
        }
    }
    for (int i = 1; i <= 2*n; i++) {
        for (int j = 1 ; j <= 2 * n; j++) {
            dp[i][j] = (j == i + 1) ? 0 : INF;
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= 2 * n; l++) {
            int r = l + len ;
            if (r > 2 * n) break;
            for (int k = l + 1; k < r ;k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + g[l][r]);
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j < n + i; j++) {
            ans = min(ans, dp[i][j] + dp[j][n+i] + g[i][j]);
        }
    }
    cout << ans << endl;
}

signed main() {
    cin >> T;
    while (T--) solve();
    return 0;
}