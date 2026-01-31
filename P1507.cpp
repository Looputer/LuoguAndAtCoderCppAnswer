//
// Created by 陆熠辰 on 26-1-11.
//
#include <iostream>
#define int long long
using namespace std;

int h, t, n;
int height[405], weight[405], ka[405];
int dp[2][405][405];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> height[i] >> weight[i] >> ka[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= h; j++) {
            for (int k = 1; k <= t; k++) {
                if (j >= height[i] && k >= weight[i])
                    dp[i & 1][j][k] = max(dp[i-1 & 1][j][k], dp[i-1 & 1][j - height[i]][k - weight[i]] + ka[i]);
                else
                    dp[i & 1][j][k] = dp[i-1 & 1][j][k];
            }
        }
    }
    cout << dp[n & 1][h][t] << endl;
    return 0;
}