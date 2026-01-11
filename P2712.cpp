//
// Created by 陆熠辰 on 25-12-28.
//
#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 505;
int n;
vector<int> v[MaxN];
int deg[MaxN], vis[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, m;
        cin >> x >> m;
        vis[x] = 1;
        for (int j = 1; j <= m; j++) {
            int y;
            cin >> y;
            v[x].push_back(y);
            deg[y]++;
        }
    }
    queue<int> q;
    for (int i = 0; i <= 500; i++) {
        if (deg[i] == 0 && vis[i] != 0) q.push(i);
    }
    vector<int> ans;
    while (q.size()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto v : v[u]) {
            deg[v]--;
            if (deg[v] == 0 && vis[v]) q.push(v);
        }
    }
    if (ans.size() == n) cout << "YES" << endl;
    else cout << n - ans.size() << endl;
    return 0;
}