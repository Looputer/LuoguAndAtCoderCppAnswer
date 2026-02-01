//
// Created by 陆熠辰 on 26-2-1.
//
#include <iostream>
#define int long long
using namespace std;

int n, m;
int dp[105][105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] |= dp[i][k] & dp[k][j];
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int win = 0, lose = 0;
        for (int j = 1; j <= n; j++) {
            win += dp[i][j];
            lose += dp[j][i];
        }
        if (win + lose == n - 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}