//
// Created by 陆熠辰 on 2026/9/12.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

struct Edge {
    int u, v, w, col;
};
const int MaxV = 5e4+5;
const int MaxE = 1e5+5;

int n, m, need;
Edge edge[MaxE];
int p[MaxV];

int pfind(int x) {
    if (x == p[x]) return x;
    else return p[x] = pfind(p[x]);
}

bool cmp1(Edge a, Edge b) {
    int x = a.w + a.col * need;
    int y = b.w + b.col * need;
    if (x != y) return x < y;
    return a.col < b.col;
}


int check(int x, int &cnt) {
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(edge + 1, edge + m + 1, [&](Edge a, Edge b) {
        int x1 = a.w + (a.col == 0 ? x : 0);
        int x2 = b.w + (b.col == 0 ? x : 0);
        if (x1 != x2) return x1 < x2;
        return a.col < b.col;
    });
    int ans = 0;
    int num = 0;
    cnt = 0;
    for (int i = 1; i <= m; i++) {
        int pu = pfind(edge[i].u);
        int pv = pfind(edge[i].v);
        if (pu == pv) continue;
        p[pu] = pv;
        ans += edge[i].w;
        if (edge[i].col == 0) {
            ans += x;
            cnt++;
        }
        num++;
        if (num == n-1) break;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> need;
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w >> edge[i].col;
        edge[i].u++;
        edge[i].v++;
    }
    int l = -1e5;
    int r = 1e5;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt;
        check(mid, cnt);
        if (cnt >= need) l = mid + 1;
        else r = mid - 1;
    }
    int cnt;
    int ans = check(r, cnt);
    cout << ans - r * need << endl;
}