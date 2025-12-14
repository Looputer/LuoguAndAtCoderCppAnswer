//
// Created by 陆熠辰 on 25-12-14.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MaxN = 2e5 + 5;
vector<int> vec[MaxN];
int dist[MaxN];

int bfs(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : vec[u]) {
            if (v == s) {
                return dist[u]+1;
            }
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
    }
    int ans = bfs(1);
    cout << ans << endl;
}