//
// Created by 陆熠辰 on 25-12-21.
//
#include <iostream>
using namespace std;

const int MaxN = 1e5+5;
int dp[MaxN][3], a[MaxN], b[MaxN], c[MaxN];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}