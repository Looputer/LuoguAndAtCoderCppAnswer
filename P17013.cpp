#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, l[MaxN], r[MaxN], full[MaxN], sz[MaxN], leaf[MaxN];

void dfs1(int u) {
    sz[u] = 1;
    if (l[u] == 0 && r[u] == 0) leaf[u] = 1;
    if (l[u]) {
        dfs1(l[u]);
        sz[u] += sz[l[u]];
    }
    if (r[u]) {
        dfs1(r[u]);
        sz[u] += sz[r[u]];
    }
}

void dfs2(int u) {
    if (leaf[u]) full[u] = 1;
    if (l[u]) dfs2(l[u]);
    if (r[u]) dfs2(r[u]);
    if (full[l[u]] && full[r[u]] && sz[l[u]] == sz[r[u]]) full[u] = 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    dfs1(1);
    dfs2(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += full[i];
    cout << ans;
}