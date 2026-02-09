//
// Created by 陆熠辰 on 26-2-18.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define int long long
using namespace std;

typedef pair<int, int> pii;
const int MaxN = 1e6+5;

vector<pii> edge[MaxN];
int dist1[MaxN], dist2[MaxN];
int n, m;

void dijkstra(int s) {
    memset(dist1, 0x3f, sizeof(dist1));
    memset(dist2, 0x3f, sizeof(dist2));
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist1[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        auto [dis, u] = pq.top();
        pq.pop();
        if (dis > dist2[u]) continue;
        for (auto [v, w] : edge[u]) {
            if (dist1[v] > dis + w) {
                dist2[v] = dist1[v];
                dist1[v] = dis + w;
                pq.push({dist1[v], v});
                pq.push({dist2[v], v});
            }
            else if (dis + w > dist1[v] && dist2[v] > dis + w) {
                dist2[v] = dis + w;
                pq.push({dist2[v], v});
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dijkstra(1);
    cout << dist2[n] << endl;
    return 0;
}