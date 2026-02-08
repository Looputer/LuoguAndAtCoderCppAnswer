//
// Created by 陆熠辰 on 26-2-8.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;
const int MaxN = 1e4+5;
vector<pii> vec[MaxN];
int dist[MaxN];
int st[MaxN];
int n, m, s;

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    dist[s] = 0;
    while (pq.size()) {
        int u = pq.top().second;
        pq.pop();
        if (st[u]) continue;
        st[u] = 1;
        for (auto v : vec[u]) {
            int j = v.first;
            int w = v.second;
            if (dist[j] > dist[u] + w) {
                dist[j] = dist[u] + w;
                pq.push({dist[j], j});
            }
        }
    }
}

signed main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == INF ? 2147483647 : dist[i]) << ' ';
    }
    return 0;
}