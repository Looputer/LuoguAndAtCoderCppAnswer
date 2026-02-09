#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define int long long
using namespace std;

const int INF = 1e18;
const int MAX_S = 2500;

struct Edge {
    int v, x, t;
};

struct Node {
    int u, s, dist;
    bool operator > (const Node &b) const {
        return dist > b.dist;
    }
};

struct Exchange {
    int c, d;
} ex[55];

int dist[55][MAX_S + 5];
vector<Edge> edges[55];
int n, m, start_coin;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> start_coin;
    for (int i = 1; i <= m; i++) {
        int u, v, x, t;
        cin >> u >> v >> x >> t;
        edges[u].push_back({v, x, t});
        edges[v].push_back({u, x, t});
    }
    for (int i = 1; i <= n; i++) {
        cin >> ex[i].c >> ex[i].d;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAX_S; j++) {
            dist[i][j] = INF;
        }
    }

    int initial_s = min(MAX_S, start_coin);
    dist[1][initial_s] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({1, initial_s, 0});

    while (!pq.empty()) {
        Node top = pq.top();
        int u = top.u;
        int s = top.s;
        int dis = top.dist;
        pq.pop();

        if (dis > dist[u][s]) continue;

        if (s < MAX_S) {
            int next_s = min((int)MAX_S, s + ex[u].c);
            if (dist[u][next_s] > dis + ex[u].d) {
                dist[u][next_s] = dis + ex[u].d;
                pq.push({u, next_s, dist[u][next_s]});
            }
        }

        for (auto &e : edges[u]) {
            if (s >= e.x) {
                int ns = s - e.x;
                if (dist[e.v][ns] > dis + e.t) {
                    dist[e.v][ns] = dis + e.t;
                    pq.push({e.v, ns, dist[e.v][ns]});
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        int ans = INF;
        for (int j = 0; j <= MAX_S; j++) {
            ans = min(ans, dist[i][j]);
        }
        cout << ans << "\n";
    }

    return 0;
}