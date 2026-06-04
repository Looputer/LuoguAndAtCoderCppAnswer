#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, a[105], dp[105][105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int len = 3; len <= n; len++) {
        for (int L = 1; L <= n; L++) {
            int R = L + len - 1;
            if (R > n) break; 
            dp[L][R] = 1e18;
            for (int k = L + 1; k < R; k++) {
                dp[L][R] = min(dp[L][R], dp[L][k] + dp[k][R] + a[L] * a[k] * a[R]);
            }
        }
    }
    cout << dp[1][n] << endl;
}