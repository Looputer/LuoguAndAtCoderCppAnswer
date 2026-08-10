//
// Created by 陆熠辰 on 2026/8/8.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, a[MaxN], x;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i-1] + a[i] > x) {
            int d = a[i - 1] + a[i] - x;
            ans += d;
            a[i] -= d;
        }
    }
    cout << ans << endl;
    return 0;
}