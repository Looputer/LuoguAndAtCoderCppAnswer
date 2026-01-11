//
// Created by 陆熠辰 on 26-1-2.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 3e5+5;
int dp[MaxN][2];
int x[MaxN], a[MaxN];
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0] + a[i], dp[i-1][1]);
        } else {
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1] + a[i], dp[i-1][0] + a[i]));
            dp[i][1] = dp[i-1][1] ;
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;

}