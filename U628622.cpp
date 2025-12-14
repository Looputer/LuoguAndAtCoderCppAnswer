//
// Created by 陆熠辰 on 25-12-14.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
const int MaxN = 2e6 + 5;

vector<pii> v[MaxN];
int dist[MaxN];

void bfs(int u) {
    memset(dist, 0x3f, sizeof(dist));
    deque<int> q;
    q.push_front(u);
    dist[u] = 0;
    while (q.size()) {
        int a = q.front();
        q.pop_front();
        for (auto [c, d] : v[a]) {
            if (dist[c] > dist[a] + d) {
                dist[c] = dist[a] + d;
                if (d == 0) {
                    q.push_front(c);
                }
                else {
                    q.push_back(c);
                }
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    bfs(s);
    cout << dist[t] << endl;
    return 0;
}