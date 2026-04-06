//
// Created by 陆熠辰 on 26-4-6.
//
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 3e3+5;
int n, m, a[MaxN], dp[MaxN][MaxN], sz[MaxN];
vector<pair<int, int> > edge[MaxN];

void dfs(int u, int fa) {
   dp[u][0] = 0;
   if (edge[u].size() == 0 && u != 1) {
      dp[u][1] = a[u];
   }
   sz[u] = 1;
   for (auto [v, w] : edge[u]) {
      if (v == fa) continue;
      dfs(v, u);
      sz[u] += sz[v];
      for (int i = min(m, sz[u]); i >= 1; i--) {
         for (int j = 1; j <= min(sz[v], i); j++) {
            if (i < j) continue;
            dp[u][i] = max(dp[u][i], dp[v][j] + dp[u][i-j] - w);
         }
      }
   }
}

signed main() {
   memset(dp, -0x3f, sizeof(dp));
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> n >> m;
   for (int i = 1; i <= n - m; i++) {
      int x;
      cin >> x;
      for (int j = 1; j <= x; j++) {
         int v, w;
         cin >> v >> w;
         edge[i].push_back(make_pair(v, w));
      }
   }
   for (int i = n - m + 1; i <= n; i++) cin >> a[i];
   dfs(1, -1);
   for (int i = m; i >= 0; i--) {
      if (dp[1][i] >= 0) {
         cout << i;
         break;
      }
   }
   return 0;
}
