//
// Created by 陆熠辰 on 25-12-21.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 105;
const int MaxW = 1e5+5;
int n, w;
int weight[MaxN], value[MaxN];
int dp[MaxN][MaxW];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    /*/
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j - weight[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][w] << endl;
    /*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i & 1][j] = dp[i - 1 & 1][j];
            if (weight[i] <= j) dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j] + value[i]);
        }
    }
    cout << dp[n & 1][w] << endl;
    return 0;
}
