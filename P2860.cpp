#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 1e5+5;

vector<pair<int, int>> edge[MaxN];
int cnt = 1;
int dfn[MaxN], low[MaxN], timer;
int eccid[MaxN], eccnt, f, r;
bool bridge[MaxN * 2];
int deg[MaxN];

void tarjan(int u, int edge_id) {
    dfn[u] = low[u] = ++timer;
    for (auto [v, id] : edge[u]) {
        if (!dfn[v]) {
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) bridge[id] = true;
        }
        else if (edge_id != id) low[u] = min(low[u], dfn[v]);
    }
}

void edcc(int u, int edge_id) {
    eccid[u] = edge_id;
    for (auto [v, id] : edge[u]) {
        if (eccid[v] || bridge[id]) continue;
        edcc(v, edge_id);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> f >> r;
    for (int i = 1; i <= r; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }
    for (int i = 1; i <= f; i++) {
        if (!dfn[i]) tarjan(i, 0);
    }
    for (int i = 1;i <= f; i++) {
        if (!eccid[i]) {
            eccnt++;
            edcc(i, eccnt);
        }
    }
    for (int u = 1; u <= f; u++) {
        for (auto [v, _] : edge[u]) {
            if (eccid[u] != eccid[v]) deg[eccid[u]]++;
        }
    }
    int leaves = 0;
    for (int i = 1; i <= eccnt; i++) {
        if (deg[i] == 1) leaves++;
    }
    cout << (leaves + 1) / 2 << endl;
}