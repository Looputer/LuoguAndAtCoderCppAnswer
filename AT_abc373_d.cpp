//
// Created by 陆熠辰 on 26-1-1.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

typedef pair<int, int> pii;
const int MaxN = 2e5+5;
int ans[MaxN], vis[MaxN];
vector<pii> vec[MaxN];
int n, m;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : vec[u]) {
        int j = v.first;
        int w = v.second;
        if (vis[j]) continue;
        ans[j] = ans[u] + w;
        dfs(j);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v, w));
        vec[v].push_back(make_pair(u, -w));
    }
    dfs(1);
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            ans[i] = 0;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}