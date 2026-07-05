#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
vector<int> edge[MaxN], redge[MaxN];
vector<int> vec;
vector<int> scc[MaxN];
int vis[MaxN], id[MaxN];
int n, m, sscnt;

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
    id[u] = sscnt;
    scc[sscnt].push_back(u);
    for (auto v : redge[u]) {
        dfs2(v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
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
            sscnt++;
            dfs2(u);
        }
    }
    
    return 0;
}