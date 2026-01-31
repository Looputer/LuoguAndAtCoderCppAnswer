//
// Created by 陆熠辰 on 26-1-25.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define int long long
using namespace std;

    const int MaxN = 1e4+5;
// struct edge {
//     int u, v, w;
// };
// vector<edge> edges;
//
    int n, m, s;
    int dist[MaxN], vis[MaxN];
    vector<pair<int, int> > vec[MaxN];
// void bellman_ford(int s) {
//     memset(dist, 0x3f, sizeof(dist));
//     dist[s] = 0;
//     for (int i = 1; i < n; i++) {
//         for (auto [u, v, w] : edges) {
//             dist[v] = min(dist[v], dist[u] + w);
//         }
//     }
// }
    void SPFA(int s) {
        memset(dist, 0x3f, sizeof(dist));
        dist[s] = 0;
        vis[s] = 1;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (pair<int, int> p : vec[u]) {
                int v = p.first;
                int w = p.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
    }
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        //edges.push_back({u, v, w});
        vec[u].push_back(make_pair(v, w));
    }
    SPFA(s);
    //bellman_ford(s);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0x3f3f3f3f3f3f3f3f) {
            dist[i] = (1ll << 31) - 1;
        }
        cout << dist[i] << " ";
    }
    return 0;
}