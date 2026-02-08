//
// Created by 陆熠辰 on 26-2-8.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e3+5;
int st[MaxN];
int dist[MaxN];
int n, m, s;
int map[MaxN][MaxN];
void Dijkstra(int s) {
    memset(st, 0, sizeof(st));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (st[j] == 0 && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        st[t] = 1;
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + map[t][j]);
        }
    }
}

signed main() {
    cin >> n >> m >> s;
    memset(map, 0x3f, sizeof(map));
    for (int i = 1; i <= n; i++) {
        map[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        map[u][v] = min(map[u][v], w);
    }
    Dijkstra(s);
    for (int i = 1; i <= n; i++) {
        if (dist[i] >= 0x3f3f3f3f3f3f3f3f / 2) cout << 2147483647 << " ";
        else cout << dist[i] << " ";
    }
    return 0;
}

