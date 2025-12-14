//
// Created by 陆熠辰 on 25-12-10.
//
#include <iostream>
#include <cstring>
using namespace std;

const int MaxN = 1e6 + 10;
int fa[MaxN], vis[MaxN];
int n, q, m, ans;

void dfs(int u) {
    vis[u]++;
    while (u != 0) {
        u = fa[u];
        vis[u]++;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> fa[i];
    }
    cin >> q;
    while (q--) {
        cin >> m;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            dfs(x);
        }
        for (int i = 1;i < n;i++) {
            if (vis[i] == m) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}