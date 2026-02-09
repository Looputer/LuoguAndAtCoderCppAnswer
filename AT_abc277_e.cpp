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
const int MaxN = 4e5+5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
vector<pii> vec[MaxN];
int dist[MaxN], st[MaxN];

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
        for (auto [v, w] : vec[u]) {
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
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0) {
            vec[u+n].push_back({v+n, 1});
            vec[v+n].push_back({u+n, 1});
        }
        else {
            vec[u].push_back({v, 1});
            vec[v].push_back({u, 1});
        }
    }
    for (int i = 1; i <= k; i++) {
        int s;
        cin >> s;
        vec[s].push_back({s+n, 0});
        vec[s+n].push_back({s, 0});
    }
    Dijkstra(1);
    int ans = min(dist[n], dist[2 * n]);
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
