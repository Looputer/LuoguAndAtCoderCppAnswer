//
// Created by 陆熠辰 on 25-12-7.
//
#include <iostream>
#include <vector>
using namespace std;
const int MaxN = 2 * 1e+5 + 5;
int vis[MaxN], deg[MaxN];
vector<int> v[MaxN];
int n, m, cnt;
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    cnt++;
    for (auto c : v[u]) {
        if (!vis[c]) dfs(c);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    dfs(1);
    if (cnt == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}