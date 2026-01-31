#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 10005;
int n, x, y;
int a[MaxN], b[MaxN];
int dp[85][MaxN][85];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= i; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j - a[i] >= 0 && k - 1 >= 0) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - a[i]][k-1] + b[i]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = n; j >= 0; j--) {
            if (dp[n][i][j] <= y) {
                ans = max(ans, min(n, j + 1));
            }
        }
    }
    cout << ans << endl;
}