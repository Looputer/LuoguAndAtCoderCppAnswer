#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 10005;

vector<int> edge[MaxN], redge[MaxN], newedge[MaxN];
vector<int> vec;

int vis[MaxN], id[MaxN];
int dp[MaxN], a[MaxN], val[MaxN];
int indeg[MaxN];

int n, m, sccnt;

void dfs1(int u) {
    vis[u] = 1;
    for (auto v : edge[u])
        if (!vis[v])
            dfs1(v);
    vec.push_back(u);
}

void dfs2(int u) {
    vis[u] = 1;
    id[u] = sccnt;
    a[sccnt] += val[u];

    for (auto v : redge[u])
        if (!vis[v])
            dfs2(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        redge[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);

    memset(vis, 0, sizeof(vis));

    reverse(vec.begin(), vec.end());

    for (auto u : vec) {
        if (!vis[u]) {
            ++sccnt;
            dfs2(u);
        }
    }

    for (int u = 1; u <= n; u++) {
        for (auto v : edge[u]) {
            int a1 = id[u];
            int a2 = id[v];

            if (a1 != a2) {
                newedge[a1].push_back(a2);
                indeg[a2]++;
            }
        }
    }

    queue<int> q;

    for (int i = 1; i <= sccnt; i++) {
        dp[i] = a[i];
        if (!indeg[i])
            q.push(i);
    }

    int ans = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ans = max(ans, dp[u]);

        for (auto v : newedge[u]) {
            dp[v] = max(dp[v], dp[u] + a[v]);

            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    cout << ans << "\n";

    return 0;
}