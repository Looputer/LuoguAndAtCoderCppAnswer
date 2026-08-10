//
// Created by 陆熠辰 on 2026/7/26.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, x[MaxN], p[MaxN], q, s[MaxN];

int bs1(int L) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (x[mid] >= L) r = mid;
        else l = mid + 1;
    }
    if (x[l] < L) return -1;
    return l;
}

int bs2(int R) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (x[mid] <= R) l = mid;
        else r = mid - 1;
    }
    if (x[l] > R) return -1;
    return l;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + p[i];
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = bs1(L), r = bs2(R);
        if (l == -1 || r == -1) cout << 0 << endl;
        else cout << s[r] - s[l-1] << endl;
    }
}