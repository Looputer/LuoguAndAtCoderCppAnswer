//
// Created by 陆熠辰 on 26-2-19.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 40005;
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> pii;

vector<pii> edge[MaxN];
vector<int> block[MaxN];
vector<pair<int, pii> > planes[MaxN];
int dist[MaxN], id[MaxN], deg[MaxN], vis[MaxN];
int n, r, p, s, cnt;

void dfs(int u, int b) {
    id[u] = b;
    block[b].push_back(u);
    for (auto [v, w] : edge[u]) {
        if (!id[v]) dfs(v, b);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> p >> s;
    for (int i = 1; i <= r; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i, ++cnt);
    }
    for (int i = 1; i <= p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        deg[id[v]]++;
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    for (int i = 1; i <= cnt; i++) {
        if (!deg[i]) q.push(i);
    }
    while (q.size()) {
        int block_id = q.front();
        q.pop();
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        for (auto u : block[block_id]) {
            if (dist[u] < INF) pq.push({dist[u], u});
        }
        while (pq.size()) {
            auto [dis, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w] : edge[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (id[u] == id[v]) pq.push({dist[v], v});
                }
            }
        }
        for (auto u : block[block_id]) {
            for (auto [v, w] : edge[u]) {
                if (id[u] != id[v]) {
                    if (--deg[id[v]] == 0) q.push(id[v]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] > INF / 2) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    }
}