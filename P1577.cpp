//
// Created by 陆熠辰 on 2026/8/2.
//
#include <iomanip>
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
const double eps = 1e-4;
int n, k;
double len[MaxN];

bool check(double mid) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += len[i] / mid;
    }
    return cnt >= k;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> len[i];
    double l = 0, r = 100000.00;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}