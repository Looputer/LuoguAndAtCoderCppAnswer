//
// Created by 陆熠辰 on 26-4-6.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e3+5;
int n, q;
int dp[MaxN][MaxN], a[MaxN], sz[MaxN];
vector<pair<int, int> > edge[MaxN];

void dfs(int u, int fa) {
    dp[u][0] = 0;
    sz[u] = 0;
    for(auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (int i = min(q, sz[u] + sz[v] + 1); i >= 1; i--) {
            for (int j = 0; j <= min(i - 1,  sz[v]); j++) {
                if (i < j) continue;
                dp[u][i] = max(dp[u][i], dp[v][j] + dp[u][i - j - 1] + w);
            }
        }
        sz[u] += sz[v] + 1;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(v, w));
        edge[v].push_back(make_pair(u, w));
    }
    dfs(1, 0);
    cout << dp[1][q];
    return 0;
}