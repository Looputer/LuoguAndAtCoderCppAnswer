//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#define int long long
using namespace std;
const int MaxN = 5 * 1e6 + 5;
int a[MaxN], d[MaxN];
signed main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    while (q--) {
        int l, r, c;
        cin >> l >> r >> c;
        d[l] += c;
        d[r+1] -= c;
    }
    int minn = 1e9;
    for (int i = 1;i <= n;i++) {
        d[i] += d[i-1];
        a[i] += d[i];
        minn = min(minn, a[i]);
    }
    cout << minn << endl;
}
