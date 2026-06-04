#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
vector<int> edge[MaxN];
int ans[MaxN], vis[MaxN], n, m;

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
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : edge[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            ans[v] = u;
            q.push(v);
        }
    }
    cout << "Yes" << endl;
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}