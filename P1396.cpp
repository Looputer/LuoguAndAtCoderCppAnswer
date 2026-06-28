#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 2e4+5;
int n, m, s, t;
vector<pair<int, int>> edge[MaxN];
int vis[MaxN];
int flag = 0;
int dfs(int u, int mid) {
    vis[u] = 1;
    if (u == t) return 1, flag = 1;
    bool res = 0;
    for (auto [v, w] : edge[u]) {
        if (w <= mid && !vis[v]) res |= dfs(v, mid);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    int l = 0, r = 1e4;
    while (l != r) {
        int mid = (l + r) / 2;
        memset(vis, 0, sizeof(vis));
        if (dfs(s, mid)) r = mid;
        else l = mid + 1;
    } 
    cout << l;
}