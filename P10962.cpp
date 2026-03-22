//
// Created by 陆熠辰 on 26-3-22.
//
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
typedef pair<int, int> pii;
vector<pii> edge[MaxN];
int dp1[MaxN], dp2[MaxN],son[MaxN],n;

void update(int u, int v, int dist) {
    if (dist >= dp1[u]) {
        dp2[u] = dp1[u];
        dp1[u] = dist;
        son[u] = v;
    }
    else if (dist >= dp2[u]) {
        dp2[u] = dist;
    }
}
void dfs1(int u, int fa) {
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        update(u, v, dp1[v] + w);
    }
}
void dfs2(int u, int fa, int w) {
    if (u != 1) {
        if (son[fa] != u) update(u, fa, dp1[fa] + w);
        else update(u, fa, dp2[fa] + w);
    }
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs2(v, u, w);
    }
}

void solve() {
    for (int i = 2; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        edge[v].push_back(pii(i, w));
        edge[i].push_back(pii(v, w));
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << dp1[i] << endl;
        edge[i].clear();
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    memset(son, 0, sizeof(son));
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) solve();

}