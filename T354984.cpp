//
// Created by 陆熠辰 on 2026/8/2.
//
#include <iomanip>
#include <iostream>
#define int long long
using namespace std;

int n;
const double eps = 1e-8;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    double l = 1, r = n;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= n) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(6) << l << endl;
}