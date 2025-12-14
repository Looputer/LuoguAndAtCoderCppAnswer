//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int a[MaxN], s[MaxN];

signed main() {
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    for (int i = 1;i<=q;i++) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}