//
// Created by 陆熠辰 on 26-1-31.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define int long long
using namespace std;

vector<pair<int, int>> edges[6205];
int vis[6205], dist[6205];
int n, m, s, t;

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
        for (auto [v, w] : edges[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }
    SPFA(s);
    cout << dist[t] << endl;
}