//
// Created by 陆熠辰 on 26-1-31.
//
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define int long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> vec[805];
int dist[805], vis[805], cow[805];
int n, p, c;
void spfa(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto [v, w] : vec[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

signed main() {
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i];
    }
    for (int i = 1; i <= c; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v, w));
        vec[v].push_back(make_pair(u, w));
    }
    int minn = 1e18;
    for (int i = 1; i <= p; i++) {
        spfa(i);
        int ans = 0;
        int reachable = 1;
        for (int j = 1;j <= n;j++) {
            if (dist[cow[j]] >= 0x3f3f3f3f3f3f3f3f / 2) {
                reachable = 0;
                break;
            }
            ans += dist[cow[j]];
        }
        minn = reachable ? min(minn, ans) : minn;
    }
    cout << minn << endl;
}
