#include <iostream>
#define int long long
using namespace std;

int n, a[5005], dp[5005][5005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << 0 << " ";
    for (int len = 2; len <= n; len++) {
        int mini = 1e18;
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n) break;
            if(len == 2) dp[l][r] = abs(a[l] - a[r]);
            else dp[l][r] = dp[l+1][r-1] + abs(a[l] - a[r]);
            mini = min(dp[l][r], mini);
        }
        cout << mini << " ";
    }

}