//
// Created by 陆熠辰 on 2026/8/8.
//
#include <iomanip>
#include <iostream>
#define int long long
#define double long double
using namespace std;

const int MaxN = 1e5+5;

struct Knight {
    int w;
    double p;
}a[MaxN];

bool cmp(Knight k1, Knight k2) {
    return k1.w * (1.0 - k2.p) > k2.w * (1.0 - k1.p) ;
}

int n, m;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].w;
    for (int i = 1; i <= m; i++) cin >> a[i].p;
    sort(a+1, a+n+1, cmp);
    double ans = 0;
    double mul = 1;
    for (int i = 1; i <= m; i++) {
        ans += mul * a[i].w;
        mul *= a[i].p;
    }
    cout << fixed << setprecision(10) << ans << endl;
}