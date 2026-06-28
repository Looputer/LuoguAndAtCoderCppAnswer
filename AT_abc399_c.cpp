#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
vector<int> edge[MaxN];
int vis[MaxN];
int n, m;

void dfs(int u) {
    vis[u] = true;
    for (auto v : edge[u]) {
        if (!vis[v]) dfs(v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m ;i ++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << m - n + cnt;
}