#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
const int MOD = 1e9+7;
int n, m, a[MaxN], dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= m; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            dp[i] = 0;
            continue;
        }
        dp[i] = dp[i-1];
        if (i >= 2) dp[i]+= dp[i-2];
        dp[i] %= MOD;
    }
    cout << dp[n] << endl;
}