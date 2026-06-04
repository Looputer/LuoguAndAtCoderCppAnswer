#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MaxN = 2e5+5;
vector<int> edge[MaxN];
int cnt[MaxN], dist[MaxN], n, m;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[1] = 0;
    cnt[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : edge[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            }
            else if (dist[v] == dist[u] + 1) {
                cnt[v] += cnt[u];
                cnt[v] %= MOD;
            }
        }
    }
    cout << cnt[n] << endl;
}