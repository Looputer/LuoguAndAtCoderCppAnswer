//
// Created by 陆熠辰 on 26-3-6.
//
#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 2e5+5;

struct Edge {
    int u, v, w;
}edge[MaxN];

int father[MaxN];
int n, m;

bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int find(int x) {
    if (father[x] == x) return x;
    return father[x] = find(father[x]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    int ans = 0, cnt = 0;

    for (int i = 1; i <= m; i++) {
        int findu = find(edge[i].u);
        int findv = find(edge[i].v);
        if (findu == findv) {
            father[findu] = findv;
            ans += edge[i].w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    cout << ans << '\n';
    return 0;
}