//
// Created by 陆熠辰 on 2026/9/13.
//
#include <iostream>
#define int long long
using namespace std;

int a, b, p;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> p;
    int ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a;
        a = a * a % p;
    }
    cout << a << "^" << b << " mod " << p << "=" << ans << endl;
}