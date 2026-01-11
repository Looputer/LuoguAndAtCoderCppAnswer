//
// Created by 陆熠辰 on 26-1-6.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 1e9+7;
int dp[1005][1005];
char s[1005][1005];
int h, w;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= w; j++) {
            s[i][j] = row[j - 1];
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1 && j == 1) continue;
            if (s[i][j] == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[h][w] << endl;
    return 0;
}