//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int a[MaxN], s[MaxN], t[MaxN];
signed main() {
    int n, q, k;
    cin>>n>>k>>q;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        t[i] = a[i] < k;
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1] + t[i];
    }
    while (q--) {
        int l, r;
        cin>>l>>r;
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}