//
// Created by 陆熠辰 on 26-1-31.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, S;
int dp[105][10005];

signed main() {
    cin >> n >> S;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int p, s, c;
        cin >> p >> s >> c;
        for (int j = 0; j <= S; j++) {
            if (dp[i-1][j] >= 0x3f3f3f3f3f3f3f3f / 2) continue;
            for (int k = 0; k <= p; k++) {
                int score = k * s;
                if (k == p) score += c;
                int ms = min(S, j + score);
                dp[i][ms] = min(dp[i][ms], dp[i-1][j] + k);
            }
        }
    }
    cout << dp[n][S] << endl;
    return 0;
}