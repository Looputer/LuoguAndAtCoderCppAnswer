#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, a[205], dp1[205][205], dp2[205][205], s[205];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    memset(dp2, 0x3f, sizeof(dp2));
    for (int i = 1; i <= 2 * n; i++) {
        s[i] = s[i-1] + a[i];
        dp2[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= 2 * n; l++) {
            int r = l + len - 1;
            if (r > 2 * n) break;
            for (int k = l; k < r; k++) {
                dp1[l][r] = max(dp1[l][r], dp1[l][k] + dp1[k+1][r] + s[r] - s[l-1]);
                dp2[l][r] = min(dp2[l][r], dp2[l][k] + dp2[k+1][r] + s[r] - s[l-1]);
            }
        }
    }
    int maxn = 0, minn = 1e18;
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, dp1[i][i+n-1]);
        minn = min(minn, dp2[i][i+n-1]);
    }
    cout << minn << endl << maxn;
}