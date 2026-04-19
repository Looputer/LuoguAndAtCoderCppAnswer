//
// Created by 陆熠辰 on 26-4-10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, q, a[MaxN], dp[MaxN][25];
vector<int> edge[MaxN];
int temp[45];

void dfs(int u, int fa) {
    dp[u][0] = 1;
    dp[u][1] = a[u];
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        int i = 1, j = 1, k = 1;
        int su = dp[u][0];
        int sv = dp[v][0];
        while (k <= 20 && (i <= su || j <= sv) ) {
            if (i <= su && (j > sv || dp[u][i] >= dp[v][j])) temp[k++] = dp[u][i++];
            else temp[k++] = dp[v][j++];
        }
        dp[u][0] = k - 1;
        for (int m = 1; m <= dp[u][0]; m++) {
            dp[u][m] = temp[m];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    while (q--) {
        int v, k;
        cin >> v >> k;
        cout << dp[v][k] << endl;
    }
    return 0;
}