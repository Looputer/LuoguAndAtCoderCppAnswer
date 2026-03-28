//
// Created by 陆熠辰 on 26-3-28.
//
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

typedef pair<int, int> pii;
const int MaxN = 2e5+5;
vector<pii> edge[MaxN];
int deg[MaxN], sdp[MaxN], bdp[MaxN], n;

void dfs1(int u, int fa) {
    sdp[u] = 0;
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        if (deg[v] == 1) sdp[u] += w;
        else sdp[u] += min(w, sdp[v]);
    }
}

void dfs2(int u, int fa) {
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        int to;
        if (deg[u] == 1) to = w;
        else to = bdp[u] - min(w, sdp[v]);
        bdp[v] = sdp[v] + min(w, to);
        dfs2(v, u);
    }
}

void solve() {
    cin >> n;
    memset(sdp, 0, sizeof(sdp));
    memset(bdp, 0, sizeof(bdp));
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++) {
        edge[i].clear();
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(pii(v, w));
        edge[v].push_back(pii(u, w));
        deg[u]++;
        deg[v]++;
    }
    dfs1(1, 0);
    bdp[1] = sdp[1];
    dfs2(1, 0);
    int maxn = 0;
    for (int i = 1; i <= n; i++) maxn = max(maxn, bdp[i]);
    cout << maxn << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}