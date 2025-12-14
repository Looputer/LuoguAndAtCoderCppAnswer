//
// Created by 陆熠辰 on 25-12-10.
//
#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e5+5;
vector<int> v[MaxN];
int n, m;
int vis[MaxN];

void dfs(int u, int &gakkou_ichi, int &gakkou_ni, bool col) {
    vis[u] = 1;
    if (col) gakkou_ichi++;
    else gakkou_ni++;
    for (int v : v[u]) {
        if (!vis[v]) dfs(v, gakkou_ichi, gakkou_ni, !col);
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int gakkou_ichi = 0, gakkou_ni = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int gakkou_a = 0, gakkou_b = 0;
            dfs(i, gakkou_a, gakkou_b, true);
            gakkou_ichi += min(gakkou_a, gakkou_b);
            gakkou_ni += max(gakkou_a, gakkou_b);
        }
    }
    cout << gakkou_ichi << " " << gakkou_ni << endl;
    return 0;
}