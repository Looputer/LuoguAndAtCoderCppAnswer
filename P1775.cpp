#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, a[305], dp[305][305], s[305];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int len = 2; len <= n; len++) {
        for (int L = 1; L <= n; L++) {
            int R = L + len - 1;
            if (R > n) break; 
            for (int k = L; k < R; k++) {
                dp[L][R] = min(dp[L][R], dp[L][k] + dp[k+1][R] + s[R] - s[L-1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}