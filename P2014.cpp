//
// Created by 陆熠辰 on 26-4-6.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e4+5;
vector<int> edge[MaxN];
int dp[MaxN][MaxN], a[MaxN], sz[MaxN];
int n, m;

void dfs(int u, int fa) {
    dp[u][1] = a[u];
    sz[u] = 1;
    for (int v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        for (int i = min(m, sz[u]); i >= 1; i--) {
            for (int j = 1; j <= min(i, sz[v]); j++) {
                if (i <= j) continue;
                dp[u][i] = max(dp[u][i], dp[u][i-j] + dp[v][j]);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x >> a[i];
        edge[x].push_back(i);
    }
    m++;
    dfs(0, -1);
    cout << dp[0][m] << endl;
    return 0;
}