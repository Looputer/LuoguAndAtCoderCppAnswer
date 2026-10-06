//
// Created by 陆熠辰 on 2026/10/6.
//
#include <iostream>
#define int long long
using namespace std;

int n, a[7];
int w[7] = {0, 1, 2, 3, 5, 10, 20};
int dp[7][1005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 6; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1000; j++) {
            for (int k = 0; k <= a[i] && j - k * w[i] >= 0; k++) {
                dp[i][j] = dp[i-1][j - k * w[i]];
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 1000; i++) if (dp[6][i]) cnt++;
    cout << cnt << endl;
}