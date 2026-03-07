//
// Created by 陆熠辰 on 26-3-6.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, k, tol;
int a[505], c[505];
int dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        tol += a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = tol; j >= a[i]; j--) {
            if (dp[j - a[i]] <= INF / 2) if (j - a[i] >= 0)  dp[j] = min(dp[j], dp[j-a[i]] + c[i]);
        }
    }
    int ans = 0;
    for (int i = tol; i >= 0; i--) {
        if (dp[i] <= k) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

