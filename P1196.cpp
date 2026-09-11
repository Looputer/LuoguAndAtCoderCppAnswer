//
// Created by 陆熠辰 on 2026/8/23.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 3e5+5;
int T;
int p[MaxN], sz[MaxN], dist[MaxN];

int pfind(int x) {
    if (p[x] == x) return p[x];
    int t = pfind(p[x]);
    dist[x] += dist[p[x]];
    p[x] = t;
    return p[x] = t;
}

void merge(int x, int y) {
    int px = pfind(x);
    int py = pfind(y);
    if (px != py) {
        dist[py] = sz[px];
        p[py] = px;
        sz[px] += sz[py];
    }
}

void init() {
    for (int i = 1; i <= 30000; i++) {
        p[i] = i;
        sz[i] = 1;
        dist[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> T;
    while (T--) {
        char op;
        int i, j;
        cin >> op >> i >> j;
        if (op == 'M') {
            merge(j, i);
        } else {
            int pi = pfind(i);
            int pj = pfind(j);
            if (pi != pj) cout << -1 << endl;
            else cout << abs(dist[j] - dist[i]) - 1 << endl;
        }
    }
}