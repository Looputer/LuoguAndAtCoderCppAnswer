#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, a[105], b[105], s[105], dp[105][505][505];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        s[i] = s[i-1] + b[i];
    }
    if (s[n] % 3) {
        cout << -1 << endl;
        return 0;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= 500; x++) {
            for (int y = 0; y <= 500; y++) {
                int z = s[i] - x - y;
                
                if (x - b[i] >= 0) {
                    dp[i][x][y] = min(dp[i][x][y], dp[i-1][x - b[i]][y] + (a[i] != 1));
                }
                if (y - b[i] >= 0) {
                    dp[i][x][y] = min(dp[i][x][y], dp[i-1][x][y - b[i]] + (a[i] != 2));
                }
                if (z - b[i] >= 0) {
                    dp[i][x][y] = min(dp[i][x][y], dp[i-1][x][y] + (a[i] != 3));
                }
            }
        }
    }
    if (dp[n][s[n] / 3][s[n] / 3] >= 0x3f3f3f3f3f3f3f3f / 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[n][s[n] / 3][s[n] / 3];
    return 0;
}