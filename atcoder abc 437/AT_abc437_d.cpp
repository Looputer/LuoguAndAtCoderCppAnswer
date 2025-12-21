//
// Created by 陆熠辰 on 25-12-20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int MOD = 998244353;
int n, m, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    vector<int> p(m+1, 0);
    for (int i = 0; i < m; i++) {
        p[i + 1] = (p[i] + b[i]) % MOD;
    }
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();
        int left = k * x % MOD - p[k] + MOD;
        left %= MOD;
        int right = ((p[m] - p[k] + MOD) % MOD - (m - k) * x % MOD + MOD) % MOD;
        ans = (ans + left + right) % MOD;
    }
    cout << ans << '\n';
    return 0;
}