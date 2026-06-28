#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 5e5+5;
const int MaxBridge = 2e6+5;
vector<pair<int, int>> edge[MaxN];
vector<int> edcc[MaxN];
vector<int> ng[MaxN];
int dfn[MaxN], low[MaxN], timer, n, m, id[MaxN], edccnt, a[MaxN], S, sum[MaxN];
bool bridge[MaxBridge], vis[MaxN];
void dfs1(int u, int fid) {
    low[u] = dfn[u] = ++timer;
    for (auto [v, eid] : edge[u]) {
        if (!dfn[v]) {
            dfs1(v, eid);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v]) bridge[eid] = 1;
        } else if (eid != fid) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void dfs2(int u) {
    vis[u] = 1;
    id[u] = edccnt;
    sum[edccnt] += a[u];
    edcc[edccnt].push_back(u);
    for (auto [v, eid] : edge[u]) {
        if (!vis[v] && !bridge[eid]) dfs2(v);
    }
}
int ans = 1e18, sz[MaxN];
void dfs3(int u, int fa) {
    sz[u] = sum[u];
    for (auto v : ng[u]) {
        if (v == fa) continue;
        dfs3(v, u);
        sz[u] += sz[v];
    }
    int x = sz[u], y = S - sz[u];
    ans = min(ans, abs(x - y));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], S += a[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }
    dfs1(1, 0);
    if (timer != n) {
        cout << -1;
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            edccnt++;
            dfs2(i);
        }
    }
    for (int i = 1; i<= n; i++) {
        for (auto [v, _] : edge[MaxN]) {
            if (id[i] != id[v]) {
                ng[id[i]].push_back(id[v]);
            }
        }
    }
    dfs3(1, -1);
    cout << ans << endl;
    return 0;
}