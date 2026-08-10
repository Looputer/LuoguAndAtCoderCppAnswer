//
// Created by 陆熠辰 on 2026/7/26.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
int n, m;
int s[MaxN], t[MaxN], d[MaxN], p[MaxN], r[MaxN];

int check(int mid) {
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= mid; i++) {
        int L = s[i], R = t[i], cnt = d[i];
        p[L] += cnt;
        p[R+1] -= cnt;
    }
    for (int i = 1; i <= n; i++) {
        p[i] += p[i-1];
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] > r[i]) return 1;
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= m; i++) {
        cin >> d[i] >> s[i] >> t[i];
    }
    int l = 1, r = m;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (check(m) == 0) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
        cout << l << endl;
    }
}