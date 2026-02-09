//
// Created by 陆熠辰 on 26-2-8.
//
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define int long long
using namespace std;

struct edge {
    int v, w, c;
};
struct node {
    int dis, cos, idx;
    bool operator < (const node &x) const {
        if (dis != x.dis) return dis > x.dis;
        return cos > x.cos;
    }
};
const int MaxN = 1e5+5;
int dist[MaxN], st[MaxN], cost[MaxN];
vector<edge> vec[MaxN];
int n, m;
void Dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));
    memset(cost, 0x3f, sizeof(cost));
    priority_queue<node> q;
    dist[s] = 0;
    cost[s] = 0;
    q.push({0, 0, s});
    while (q.size()) {
        int u = q.top().idx;
        q.pop();
        if (st[u]) continue;
        st[u] = 1;
        for (auto tmp : vec[u]) {
            int j = tmp.v;
            int w = tmp.w;
            int c = tmp.c;
            if (dist[j] > dist[u] + w) {
                dist[j] = dist[u] + w;
                cost[j] = cost[u] + c;
                q.push({dist[j], cost[j], j});
            }
            else if (dist[j] == dist[u] + w) {
                if (cost[j] > cost[u] + c) {
                    cost[j] = cost[u] + c;
                    q.push({dist[j], cost[j], j});
                }
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        vec[u].push_back({v, w, c});
        vec[v].push_back({u, w, c});
    }
    Dijkstra(1);
    cout << dist[n] << " " << cost[n] << endl;
    return 0;
}