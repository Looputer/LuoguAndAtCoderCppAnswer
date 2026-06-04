#include <iostream>
#define int long long
using namespace std;

const int INF = 1e18;
int n, k, a[5005], dp[5005][2];

int L(int i) {
    if (i <= 1) return 0;
    return max(0ll, a[i-1] - a[i] + 1);
}

int R(int i) {
    if (i >= n) return 0;
    return max(0ll, a[i+1] - a[i] + 1);
}

int B(int p, int i) {
    return max(0ll, a[i-1] - min(a[p], a[i]) + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n ; i++) cin >> a[i];
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][1] = L(i) + R(i);
    }
    for (int j = 2; j <= k; j++) {
        int current = j % 2;
        int prev = (j - 1) % 2;
        for (int i = 1; i <= n; i++) {
            dp[i][current] = INF;
        }
        int minn = INF;
        for (int i = 1; i <= n; i++) {
            if (i >= 4) minn = min(minn, dp[i-3][prev]);
            if (i >= 3) {
                if (dp[i-2][prev] != INF) dp[i][current] = min(dp[i][current], dp[i-2][prev] - R(i-2) + B(i-2, i) + R(i));
            }
            if (minn != INF) dp[i][current] = min(dp[i][current], minn + L(i) + R(i));
        }
    }
    int ans = INF;
    int finall = k % 2;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i][finall]);
    }
    cout << ans << endl;
    return 0;
}