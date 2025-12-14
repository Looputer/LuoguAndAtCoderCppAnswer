//
// Created by 陆熠辰 on 25-12-14.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MaxN = 1e4 + 5;

int ans;
vector<int> vec[MaxN];
int dist1[MaxN], dist2[MaxN];

void bfs(int s, int dist[]) {
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

void dfs(int u, int fa, int dis) {
    ans++;
    for (auto &v : vec[u]) {
        if (v == fa || dist1[v] == dist2[v]) continue;
        if (dis) dfs(v, u, dis - 1);
    }
}
void solve() {
    ans = 0;
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1;i <= n;i++) {
        vec[i].clear();
        dist1[i] = dist2[i] = 0x3f3f3f3f;
    }
    for (int i = 2;i <= n;i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    bfs(a, dist1);
    bfs(b, dist2);
    for (int i = 1;i <= n;i++) {
        if (dist1[i] == dist2[i] && dist1[i] != 0) {
            dfs(i, -1, dist1[i] - 1);
        }
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}