//
// Created by 陆熠辰 on 26-2-18.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define int long long
using namespace std;

typedef pair<int,int> pii;
const int MaxN = 1e6+5;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pii> edge[MaxN];
int vis[MaxN], dist[MaxN];
int n, m, k, s, t;

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    while (pq.size()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : edge[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
        for (int j = 1; j <= k; j++) {
            edge[u + (j-1) * n].push_back({v + j * n, 0});
            edge[v + (j-1) * n].push_back({u + j * n, 0});
            edge[u + j * n].push_back({v + j * n, w});
            edge[v + j * n].push_back({u + j * n, w});
        }
    }
    for (int i = 1; i <= k; i++) {
        edge[t + (i - 1) * n].push_back({t + i * n, 0});
    }
    dijkstra(s);
    cout << dist[t + k * n] << endl;
    return 0;
}