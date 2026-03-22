//
// Created by 陆熠辰 on 26-3-20.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, a[MaxN], costdn[MaxN], dn[MaxN], up[MaxN];
vector<pair<int, int> > vec[MaxN];

void dfs(int u, int fa, int current_net, int min_net) {
    dn[u] = max(0ll, -min_net);
    for (auto [v, w] : vec[u]) {
        if (v == fa) continue;
        int next_net = current_net + a[u] - w;
        int next_min = min(min_net, next_net);
        costdn[v] = costdn[u] - w + a[v];
        up[v] = max(0ll, max(up[u] + w - a[v], w - a[v]));
        dfs(v, u, next_net, next_min);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v, w));
        vec[v].push_back(make_pair(u, w));
    }
    dfs(1, -1, 0, 0);
    for (int i = 2; i <= n; i++) cout << dn[i] << " ";
    cout << endl;
    for (int i = 2; i <= n; i++) cout << up[i] << " ";
    return 0;
}