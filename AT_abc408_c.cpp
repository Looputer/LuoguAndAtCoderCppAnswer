//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#define int long long
using namespace std;
const int MaxN = 1e6+5;
int a[MaxN];
signed main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        a[l] += 1;
        a[r + 1] -= 1;
    }
    int minn = 1e9;
    for (int i = 1; i <= n; i++) {
        a[i] += a[i-1];
        minn = min(minn, a[i]);
    }
    cout << minn + 1 << endl;
}