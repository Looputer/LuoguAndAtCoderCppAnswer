//
// Created by 陆熠辰 on 26-1-11.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 5e2+5;
const int INF = 0x3f3f3f3f;
int a[MaxN], n, K, dp[MaxN][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, K); j++) {
            int maxn = -1e9, minn = 1e9;
            for (int k = i; k >= j; k--) {
                if (a[k] > maxn) maxn = a[k];
                if (a[k] < minn) minn = a[k];
                dp[i][j] = min(dp[i][j], dp[k-1][j-1] + maxn - minn);
            }
        }
    }
    cout << dp[n][K] << endl;
    return 0;
}