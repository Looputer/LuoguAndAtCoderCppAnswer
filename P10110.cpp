//
// Created by 陆熠辰 on 2026/9/11.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, m, a, b;
int v[MaxN];
vector<int> edge[MaxN];
int dist[MaxN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
    }
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto next : edge[u]) {
            if (dist[next] != -1) continue;
            dist[next] = dist[u] + 1;
            q.push(next);
        }
    }
    if (dist[b] == -1) cout << "No solution";
    else cout << v[b] - v[a] + dist[b];
}
