//
// Created by 陆熠辰 on 26-1-11.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MaxN = 5e3+5;

int dp[MaxN];
int n, s;
int a[MaxN];
int sum[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (sum[i] - sum[j-1] >= s)
                dp[i] += dp[j-1];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;
}