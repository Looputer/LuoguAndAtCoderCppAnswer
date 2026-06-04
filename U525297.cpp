#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, a[305], dp[305][305];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n+1] = 1;
    for (int len = 3; len <= n + 2; len++) {
        for (int l = 0; l <= n; l++) {
            int r = len + l - 1;
            if (r > n + 1) break;
            for (int k = l + 1; k < r; k++) dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[r] * a[k]);
        }
    }
    cout << dp[0][n+1] << endl;
}