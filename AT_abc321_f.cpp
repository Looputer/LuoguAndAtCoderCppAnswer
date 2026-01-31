//
// Created by 陆熠辰 on 26-1-25.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 998244353;
int q, k;
int dp[5005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q >> k;
    dp[0] = 1;
    for (int i = 1; i <= q; i++) {
        char query;
        int x;
        cin >> query >> x;
        if (query == '+') {
            for (int j = 5000; j >= x; j--) dp[j] = (dp[j] + dp[j - x]) % MOD;
        }
        else {
            for (int j = x; j <= 5000; j++) dp[j] = (dp[j] - dp[j - x] + MOD) % MOD;
        }
        cout << dp[k] << endl;
    }
}
