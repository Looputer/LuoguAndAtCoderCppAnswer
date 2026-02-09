//
// Created by 陆熠辰 on 26-2-9.
//
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define int long long
using namespace std;

typedef pair<int, int> pii;
const int MaxN = 2e5+5;
int n, m, x;
int dist[MaxN * 2], st[MaxN * 2];
vector<pii> edge[2 * MaxN];

void Dijkstra(int s) {
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
        for (auto [v,w] : edge[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, 1});
        edge[v+n].push_back({u+n, 1});
    }
    for (int i = 1; i <= n; i++) {
        edge[i].push_back({i+n, x});
        edge[i+n].push_back({i, x});
    }
    Dijkstra(1);
    cout << min(dist[n], dist[2 * n]) << endl;
}