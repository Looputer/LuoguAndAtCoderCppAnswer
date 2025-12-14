//
// Created by 陆熠辰 on 25-12-9.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MaxN = 3 * 1e5 + 5;
int n, m, q;
vector<int> v[MaxN];
int vis[MaxN];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto c : v[u]) {
        if (vis[c]) continue;
        dfs(c);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            dfs(b);
        }
        if (a == 2) {
            if (vis[b]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}