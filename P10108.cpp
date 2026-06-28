#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e4+5;
int a[MaxN], b[MaxN], dp[MaxN], n, m;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    memset(dp, -0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - a[j] >= 0 && i - a[j] < n) dp[i] = max(dp[i], dp[i-a[j]] + b[i-a[j]]);
        }
    }
    int ans = -1e9;
    for (int i = n; i <= 2 * n; i++) ans = max(dp[i], ans);
    cout << ans;
}