//
// Created by 陆熠辰 on 25-12-28.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
int n, m, r, q;
int dist[MaxN], vis[MaxN];
vector<int> vec[MaxN];

void bfs(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : vec[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cin >> q;
    bfs(r);
    cout << "I'm here!\n";
    while (q--) {
        int a, b;
        cin >> a >> b;
        int t = dist[a];
        int j = dist[b];
        if (t <= j) cout << "Terry\n";
        else  cout << "Jom\n";
    }
    return 0;
}