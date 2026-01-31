//
// Created by 陆熠辰 on 26-1-11.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e2+5;
int n, K;
int a[MaxN], dp[MaxN][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, K); j++) {
            int maxn = -1e9, minn = 1e9;
            for (int k = i; k >= j; k--) {
                if (a[k] > maxn) maxn = a[k];
                if (a[k] < minn) minn = a[k];
                dp[i][j] = max(dp[i][j], dp[k-1][j-1] + maxn - minn);
            }
        }
    }
    cout << dp[n][K] << endl;
    return 0;
}