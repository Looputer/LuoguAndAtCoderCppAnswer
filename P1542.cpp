//
// Created by 陆熠辰 on 2026/8/2.
//
#include <iostream>
#include <iomanip>
#define int long long
#define double long double
using namespace std;

const double eps = 1e-4;
const int MaxN = 2e5+5;
int n, x[MaxN], y[MaxN], s[MaxN];
int check(double mid) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        double cost = s[i] / mid;
        sum += cost;
        if (sum > y[i]) return 0;
        if (sum < x[i]) sum = x[i];
    }
    return 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> s[i];
    double l = 0, r = 1e8;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(2) << l << endl;
}