#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
vector<int> edge[MaxN], redge[MaxN];
vector<int> vec;
vector<int> scc[MaxN];
int vis[MaxN], id[MaxN], indeg[MaxN], outdeg[MaxN];
int n, sccnt;

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
    for (auto v : redge[u]) {
        dfs2(v);
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        while (cin >> x && x) {
            edge[i].push_back(x);
            redge[x].push_back(i);
        }
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
            int a = id[i];
            int b = id[v];
            if (a != b) {
                indeg[b]++;
                outdeg[a]++;
            }
        }
    }
    int in = 0, out = 0;
    for (int i = 1; i <= sccnt; i++) {
        if (!indeg[i]) in++;
        if (!outdeg[i]) out++;
    }
    cout << in << endl;
    if (sccnt == 1) cout << 0 << endl;
    else cout << max(in, out) << endl;
}