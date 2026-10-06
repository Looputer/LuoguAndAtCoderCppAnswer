#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define int long long
using namespace std;

const int MaxN = 5005;
const int INF = 4e18;

struct Edge {
    int u, v, w, b;
};

int n, m;
vector<Edge> edge;
vector<pair<int, int>> g[MaxN];

int dis1[MaxN];
int disn[MaxN];

void dijkstra(int s, int dis[]) {
    for (int i = 1; i <= n; i++)
        dis[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();

        if (d != dis[u])
            continue;

        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w, b;
        cin >> u >> v >> w >> b;
        edge.push_back({u, v, w, b});
    }

    sort(edge.begin(), edge.end(), [](Edge a, Edge b) {
        return a.b < b.b;
    });

    int ans = INF;

    int i = 0;

    while (i < m) {
        int j = i;

        while (j < m && edge[j].b == edge[i].b) {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            g[u].push_back({v, w});
            g[v].push_back({u, w});

            j++;
        }

        dijkstra(1, dis1);
        dijkstra(n, disn);

        for (int k = i; k < j; k++) {
            int u = edge[k].u;
            int v = edge[k].v;

            if (dis1[u] != INF && disn[v] != INF)
                ans = min(ans, dis1[u] + disn[v]);

            if (dis1[v] != INF && disn[u] != INF)
                ans = min(ans, dis1[v] + disn[u]);
        }

        i = j;
    }

    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}