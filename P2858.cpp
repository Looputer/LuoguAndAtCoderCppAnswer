#include <iostream>
#define int long long
using namespace std;

int n, a[2005], dp[2005][2005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n) break;
            int day = n - r + l;
            dp[l][r] = max(a[l] * day + dp[l+1][r], a[r] * day + dp[l][r-1]);
        }
    }
    cout << dp[1][n] << endl;
}