//
// Created by 陆熠辰 on 2026/8/23.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 5e5+5;
struct Node {
    int u, v, f;
}edge[MaxN];
int n, m, e, q;
int p[MaxN], x[MaxN], flag[MaxN], sz[MaxN], ans[MaxN];

int pfind(int u) {
    if (u == p[u]) return u;
    return p[u] = pfind(p[u]);
}

void merge(int _x, int y) {
    int px = pfind(_x), py = pfind(y);
    if (px == py) return;
    p[px] = py;
    sz[px] += sz[py];
}

void init() {
    for (int i = 1; i <= n+m; i++) {
        p[i] = i;
        sz[i] = 1;
        if (i > n) flag[i] = 1;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> e;
    init();
    for (int i = 1; i <= e; i++) {
        cin >> edge[i].u >> edge[i].v;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x[i];
        edge[x[i]].f = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= e; i++) {
        if (edge[i].f) continue;
        int u = edge[i].u, v = edge[i].v;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        int pi = pfind(i);
        if (flag[pi]) cnt++;
    }
    for (int i = q; i >= 1; i--) {
        int u = edge[x[i]].u, v = edge[x[i]].v;
        int pu = pfind(u), pv = pfind(v);
        if (pu == pv) continue;
        if (flag[pu] + flag[pv] == 1) {
            if (flag[pu]) cnt += sz[pv];
            else cnt += sz[pu];
        }
        merge(u, v);
        ans[i] = cnt;
    }
    for (int i = q; i >= 1; i--) {
        cout << ans[i] << endl;
    }
}