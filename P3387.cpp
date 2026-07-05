#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
vector<int> edge[MaxN], redge[MaxN], newedge[MaxN];
vector<int> vec;
vector<int> scc[MaxN];
int vis[MaxN], id[MaxN], dp[MaxN], a[MaxN], val[MaxN];
int n, m, sccnt;

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
    a[sccnt] += val[u];
    for (auto v : redge[u]) {
        dfs2(v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= m; i++) {
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
            dfs2(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto v : edge[i]) {
            if (id[i] != id[v]) newedge[id[v]].push_back(id[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= sccnt; i++) {
        dp[i] = a[i];
        for (auto v : newedge[i]) {
            dp[i] = max(dp[i], a[i] + dp[v]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}