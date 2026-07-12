#include <iostream>
#define int long long
using namespace std;

int n, a[105], dp[105][105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n) break;
            for (int k = l; k <= r; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k-1] + dp[k+1][r] + a[l-1] + a[r+1]);
            }
        }
    }
    cout << dp[1][n];
}