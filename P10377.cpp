//
// Created by 陆熠辰 on 26-3-12.
//
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int INF = 1e18;
int a[15], b[15], dp[1 << 9][15];
int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int limit = 1 << n;
    for (int s = 0; s < limit; s++)
        for (int i = 1; i <= n; i++)
            dp[s][i] = INF;
    for (int i = 1; i <= n; i++) dp[1 << (i-1)][i] = 0;
    for (int s = 0; s < limit; s++) {
        for (int i = 1; i <= n; i++) {
            if (!(s & (1 << (i-1)))) continue;
            if (dp[s][i] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (s & (1 << (j-1))) continue;
                int ns = s | (1 << (j - 1));
                dp[ns][j] = min(dp[ns][j], dp[s][i] + max(b[i], a[j]));
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) ans = min(ans, dp[limit-1][i]);
    cout << ans + n << endl;
    return 0;
}
