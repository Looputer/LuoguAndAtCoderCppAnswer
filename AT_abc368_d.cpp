//
// Created by 陆熠辰 on 26-1-1.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int vis[MaxN], sz[MaxN];
vector<int> v[MaxN];

void dfs(int u, int fa) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : v[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= k; i++) {
        int a;
        cin >> a;
        sz[a] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sz[i] && sz[i] < k) ans++;
    }
    cout << ans + 1 << endl;
}