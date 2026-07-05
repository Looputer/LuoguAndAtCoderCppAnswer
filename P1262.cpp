#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
vector<int> edge[MaxN], redge[MaxN], newedge[MaxN];
vector<int> vec;
vector<int> scc[MaxN];
int vis[MaxN], id[MaxN], a[MaxN], val[MaxN], deg[MaxN], mi[MaxN];
int n, p, sccnt, r;

void dfs1(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : edge[u]) {
        dfs1(v);
    }
    vec.push_back(u);
}

void dfs2(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    id[u] = sccnt;
    scc[sccnt].push_back(u);
    a[sccnt] = min(a[sccnt], val[u]);
    mi[sccnt] = min(mi[sccnt], u);
    for (auto v : redge[u]) {
        dfs2(v);
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    memset(val, 0x3f, sizeof(val));
    for (int i = 1; i <= p; i++) {
        int x;
        cin >> x >> val[x];
    }
    cin >> r;
    for (int i = 1; i <= r; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        redge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs1(i);
    }
    memset(vis, 0, sizeof(vis));
    reverse(vec.begin(), vec.end());
    for (auto u : vec) {
        if (!vis[u]) {
            sccnt++;
            a[sccnt] = 0x3f3f3f3f3f3f3f3f;
            mi[sccnt] = u;
            dfs2(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto v : edge[i]) {
            if (id[i] != id[v]) {
                newedge[id[i]].push_back(id[v]);
                deg[id[v]]++;
            }
        }
    }
    int ans = 0, flag = 0, minn = 1e18;
    for (int i = 1; i <= sccnt; i++) {
        if (deg[i] == 0 && a[i] == 0x3f3f3f3f3f3f3f3f) {
            flag = 1;
            minn = min(minn, mi[i]);
            continue;
        }
        if (deg[i] == 0) ans += a[i];
    }
    if (flag) {
        cout << "NO" << endl << minn;
    } else {
        cout << "YES" << endl << ans;
    }
    return 0;
}