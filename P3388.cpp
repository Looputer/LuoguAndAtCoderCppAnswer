#include <iostream>
#include <vector>
#include <set>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
vector<pair<int, int>> edge[MaxN];
int dfn[MaxN], low[MaxN], timer, n, m;
bool cut[MaxN], bridge[MaxN];
set<int> st;
void dfs(int u, int fid) {
    low[u] = dfn[u] = ++timer;
    int son = 0;
    for (auto [v, eid] : edge[u]) {
        if (!dfn[v]) {
            son++;
            dfs(v, eid);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v] && fid) {
                cut[u] = 1;
                st.insert(u);
            }
        } else if (eid != fid) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (fid == 0 && son >= 2){ 
        cut[u] = 1;
        st.insert(u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i, 0);
    }
    cout << st.size() << endl;
    for (auto c : st) cout << c << " ";
    return 0;
}