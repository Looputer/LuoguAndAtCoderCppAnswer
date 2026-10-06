//
// Created by 陆熠辰 on 2026/10/5.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 5e3+5;
const int MOD = 1e9+7;
int n, s, a[MaxN], dp[MaxN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j >= 1; j--) {
            sum += a[j];
            if (sum >= s) {
                dp[i] += dp[j - 1];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
}