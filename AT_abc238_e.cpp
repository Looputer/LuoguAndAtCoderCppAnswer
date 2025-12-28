//
// Created by 陆熠辰 on 25-12-28.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
vector<int> vec[MaxN];
int vis[MaxN];
int n, q;
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : vec[u]) {
        if (!vis[v]) dfs(v);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1;i <= q;i++) {
        int l, r;
        cin >> l >> r;
        vec[l-1].push_back(r);
        vec[r].push_back(l-1);
    }
    dfs(0);
    if (vis[n]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}