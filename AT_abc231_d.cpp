#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
vector<int> edge[MaxN];
bool vis[MaxN];
int deg[MaxN], n, m;

bool check(int u, int fa) {
    vis[u] = true;
    for (auto v : edge[u]) {
        if (!vis[v]) {
            if (check(v, u)) {
                return 1;
            }
        }
        else if (v != fa) {
            return 1;
        }
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        deg[u]++;
        deg[v]++;
        if (deg[u] > 2 || deg[v] > 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (check(i, -1)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}