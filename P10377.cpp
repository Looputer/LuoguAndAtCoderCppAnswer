//
// Created by 陆熠辰 on 26-3-12.
//
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int a[15], b[15], dp[15];
int n;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) dp[i] = i;
    int ans = 1e18;
    do {
        int pos = 0;
        for (int i = 2; i <= n; i++) {
            int x = dp[i-1];
            int y = dp[i];
            pos += max(b[x], a[y]) + 1;
        }
    } while (next_permutation(dp+1, dp+n+1));
    cout << ans << endl;
}
