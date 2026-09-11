//
// Created by 陆熠辰 on 2026/8/22.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 4e5+5;
int p[MaxN], l[MaxN], r[MaxN], coords[MaxN], orderIdx[MaxN];
int t, n;

int find(int x) {
    while (p[x] != x) {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}

int bs(int idx, int maxn) {
    int L = 1, R = maxn + 1;
    while (l < r) {
        int mid = (L + R) / 2;
        if (coords[mid] < maxn) L = mid + 1;
        else R = mid;
    }
    return L;
}

bool cmp(int a, int b) {
    return r[a] < r[b];
}

void solve() {
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        coords[++cnt] = l[i];
        coords[++cnt] = r[i];
    }
    sort(coords + 1, coords + cnt + 1);
    int len = unique(coords + 1, coords + cnt + 1) - coords - 1;
    for (int i = 1; i <= len + 1; i++) p[i] = i;
    for (int i = 1; i <= n; i++) orderIdx[i] = i;
    sort(orderIdx + 1, orderIdx + n + 1, cmp);
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        int idx = orderIdx[i];
        int L = bs(len, l[idx]);
        int R = bs(len, r[idx]);
        int f = find(L);
        if (f > R) {
            flag = 0;
            break;
        }
        p[f] = find(f+1);
    }
    cout << (flag ? "Yes" : "No") << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}