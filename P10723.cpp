#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, a[MaxN], deg[MaxN];
vector<int> edge[MaxN];
bool removed[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) cnt++;
    }
    if (cnt <= 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1 && a[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        removed[u] = true;
        for (auto v : edge[u]) {
            if (removed[v]) continue;
            deg[v]--;
            if (deg[v] == 1 && a[v] == 0) q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!removed[i] && a[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}