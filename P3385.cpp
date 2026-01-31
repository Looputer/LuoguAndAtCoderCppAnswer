//
// Created by 陆熠辰 on 26-1-25.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 2e3+5;
int T;
vector<pair<int, int> > vec[MaxN];
int vis[MaxN], dist[MaxN], cnt[MaxN];

bool SPFA(int s, int n) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto p : vec[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                q.push(v);
            }
            if (cnt[v] >= n) {
                return 1;
            }
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return 0;
}
void solve() {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vec[i].clear();
    }
    for (int i = 1 ; i <= m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w >= 0) {
            vec[v].push_back(make_pair(u, w));
            vec[u].push_back(make_pair(v, w));
        }
        else {
            vec[u].push_back(make_pair(v, w));
        }
    }
    bool flag = SPFA(1, n);
    cout << (flag ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}