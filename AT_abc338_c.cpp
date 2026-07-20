//
// Created by 陆熠辰 on 2026/7/19.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 5e5+5;
int n, a[MaxN];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    int R = 0;
    for (int L = 1; L <= n; L++) {
        while (R < n && a[R] < a[L] * 2) {
            R++;
        }
        if (a[R] >= a[L] * 2) cnt += n - R + 1;
    }
    cout << cnt << endl;
}