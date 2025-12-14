//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int a[MaxN], d[MaxN];

signed main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    d[n+1] = 1;
    int mod = 1e5+7;
    for (int i = n;i >= 1;i--) {
        d[i] = d[i+1] * a[i] % mod;
    }
    while (q--) {
        int x;
        cin >> x;
        cout << d[n-x+1] << endl;
    }
}