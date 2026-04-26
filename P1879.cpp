#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MOD = 1e8;
int m, n, a[14][14], dp[15][1<<12];

bool check(int x, int y) {
    for (int i = 0; i < m; i++) {
        if (a[x][i] == 0 && (y >> i & 1) == 1) return true;
    }
    return false;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 1;i <= n; i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (j & j << 1) continue;
            if (check(i, j)) continue;
            for (int k = 0; k < (1 << m); k++) {
                if (check(i-1, k)) continue;
                if (k & k << 1) continue;
                if (j & k) continue;
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < (1 << m); i++) {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}