//
// Created by 陆熠辰 on 2026/8/2.
//
#include <iomanip>
#include <iostream>
#define int long long
#define double long double
using namespace std;

const int MaxN = 1e5+5;
const double eps = 1e-6;
int n, p, a[MaxN], b[MaxN];

bool check(double mid) {
    double sum = p * mid;
    for (int i = 1; i <= n; i++) {
        double cost = a[i] * mid;
        if (b[i] < cost) sum -= cost - b[i];
    }
    return sum >= 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        t += a[i];
    }
    double l = 0, r = 1e18;
    if (t <= p) {
        cout << -1 << endl;
        return 0;
    }
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(6) << l << endl;
}
