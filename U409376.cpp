//
// Created by 陆熠辰 on 26-1-18.
//
#include <iostream>
#define int long long
using namespace std;

int n, u, v;
int w[55], x[55], y[55];
int dp[55][505][505];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> u >> v;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= u; j++) {
            for (int k = 0; k <= v; k++) {
                int t1 = 0, t2 = 0, t3 = 0;
                t1 = dp[i-1][j][k];
                if (j - w[i] >= 0) {
                    t2 = dp[i-1][j-w[i]][k] + x[i] * w[i];
                }
                else if (k - w[i] >= 0) {
                    t3 = dp[i-1][j][k-w[i]] + y[i] * w[i];
                }
                dp[i][j][k] = max(t1, max(t2, t3));
            }
        }
    }
    cout << dp[n][u][v] << endl;
    return 0;
}