//
// Created by 陆熠辰 on 25-12-13.
//
#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e5 + 5;
vector<int> v[MaxN];
int vis[MaxN];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto c : v[u]) {
        dfs(c);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans - 1 << endl;
    return 0;
}