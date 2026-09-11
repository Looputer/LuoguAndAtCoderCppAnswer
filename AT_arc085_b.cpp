//
// Created by 陆熠辰 on 2026/9/5.
//
#include <iostream>
#define int long long
using namespace std;

int n, z, w;
int a[2005];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> z >> w;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = (1ll << 60);
    for (int i = 1; i < n; i++) {
        ans = max(ans, abs(a[i] - a[n]));
    }
    ans = max(abs(a[n] - w), ans);
    cout << ans << endl;
}