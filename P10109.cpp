//
// Created by 陆熠辰 on 25-12-10.
//
#include <iostream>
#include <cstring>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 305;
int n, q, vis[MaxN], ans;
vector<int> edge[MaxN];

void dfs(int u, int cnt) {
    vis[u]++;
    if (vis[u] == cnt) {
        ans = u;
        return;
    }
    for (auto v : edge[u]) {
        if (v != u) dfs(v, cnt);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i <= n - 1; i++) {
        int f;
        cin >> f;
        edge[i].push_back(f);
        edge[f].push_back(i);
    }
    while (q--) {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        int x;
        cin >> x;
        for (int i = 1; i <= x; i++) {
            int h;
            cin >> h;
            dfs(h, x);
        }
        cout << ans << endl;
    }
}