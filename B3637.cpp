//
// Created by 陆熠辰 on 26-1-11.
//
//
// Created by 陆熠辰 on 26-1-2.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
int a[MaxN], dp[MaxN];
int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxn = -1e9;
    for (int i = 1; i <= n; i++) {
        if (maxn < dp[i]) {
            maxn = dp[i];
        }
    }
    cout << maxn << '\n';
    return 0;
}