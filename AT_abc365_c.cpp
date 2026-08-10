//
// Created by 陆熠辰 on 2026/8/2.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, m, a[MaxN], sum;

bool check(int mid) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += min(a[i], mid);
    }
    return ans > m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    };
    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (sum <= m) cout << "infinite";
    else cout << l << endl;
}