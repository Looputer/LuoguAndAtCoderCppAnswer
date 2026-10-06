//
// Created by 陆熠辰 on 2026/9/11.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, t;
vector<int> edge[MaxN], unedge[MaxN];
int treasure[MaxN], deg[MaxN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        edge[i].clear(), unedge[i].clear();
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++) {
        cin >> treasure[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        unedge[x].push_back(y);
        unedge[y].push_back(x);
        deg[x]++, deg[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1 && treasure[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        deg[u] = 0;
        for (auto v : unedge[u]) {
            if (deg[v] > 0) {
                deg[v]--;
                if (deg[v] == 1 && treasure[v] == 0) q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
}