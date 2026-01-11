//
// Created by 陆熠辰 on 25-12-28.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int MaxN = 5e4+5;
int n, m;
vector<pii> vec[MaxN];
int deg[MaxN], dist[MaxN];
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(dist, -0x3f, sizeof(dist));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
        deg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    dist[1] = dist[0] = 0;
    vector<int> ans;
    while (q.size()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto [v, w] : vec[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    if (dist[n] < -INF / 2) dist[n] = -1;
    cout << dist[n] << endl;
    return 0;
}