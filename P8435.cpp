#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 5e5+5;
const int MaxBridge = 2e6+5;
vector<pair<int, int>> edge[MaxN];
vector<int> edcc[MaxN];
int dfn[MaxN], low[MaxN], timer, n, m, id[MaxN], edccnt;
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
    edcc[edccnt].push_back(u);
    for (auto [v, eid] : edge[u]) {
        if (!vis[v] && !bridge[eid]) dfs2(v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs1(i, 0);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            edccnt++;
            dfs2(i);
        }
    }
    cout << edccnt << endl;
    for (int i = 1; i <= edccnt; i++) {
        cout << edcc[i].size() << " ";
        for (auto c : edcc[i]) cout << c << " ";
        cout << endl;
    }
    return 0;
}