//
// Created by 陆熠辰 on 26-1-22.
//
#include <iostream>
#define int long long
using namespace std;

int n, dp[1005], is_prime[1005], cnt;

bool prime(int u) {
    if (u == 2) return true;
    for (int i = 2; i * i <= u; i++) {
        if (u % i == 0) return false;
    }
    return true;
}

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (prime(i)) is_prime[++cnt] = i;
    }
    dp[0] = 1;
    for (int i = 1; i <= cnt; i++) {
        for (int j = is_prime[i]; j <= n; j++) {
            dp[j] += dp[j - is_prime[i]];
        }
    }
    cout << dp[n] << endl;
}