//
// Created by 陆熠辰 on 2026/10/4.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int n, s;
int dp[5005], t[5005], f[5005], st[5005], sf[5005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> f[i];
        st[i] = st[i-1] + t[i];
        sf[i] = sf[i-1] + f[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int cost = (sf[i] - sf[j]) * s * (sf[n] - sf[j]);
            dp[i] = min(dp[i], dp[j] + cost);
            //cout << sf[i] - st[j] << " " << k-1 << " " << dp[j][k-1] << " " << cost<< endl;
        }
    }
    cout << dp[n] << endl;
}