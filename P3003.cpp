//
// Created by 陆熠辰 on 26-2-8.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

typedef pair<int, int> pii;
const int MaxN = 1e5+5;
int c, p, pb, pa1, pa2;
vector<pii> vec[MaxN];
int dist[MaxN];
int st[MaxN];

void Dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (pq.size()) {
        int u = pq.top().second;
        pq.pop();
        if (st[u]) continue;
        st[u] = 1;
        for (auto v : vec[u]) {
            int j = v.first;
            int w = v.second;
            if (dist[j] > dist[u] + w) {
                dist[j] = dist[u] + w;
                pq.push(make_pair(dist[j], j));
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> p >> pb >> pa1 >> pa2;
    for (int i = 1; i <= c; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v, w));
        vec[v].push_back(make_pair(u, w));
    }
    int sp1 = 0, sp2 = 0;
    Dijkstra(pa1);
    sp1 = dist[pb] + dist[pa2];
    Dijkstra(pa2);
    sp2 = dist[pb] + dist[pa1];
    cout << min(sp1, sp2) << endl;
    return 0;
}