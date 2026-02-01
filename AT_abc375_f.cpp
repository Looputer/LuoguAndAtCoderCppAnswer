//
// Created by 陆熠辰 on 26-2-1.
//
#include <iostream>
#include <cstring>
#include <vector>
#define int long long
#define pii pair<int, pair<int, int> >
using namespace std;

struct node {
    int u, v, w;
}a[305];
const int INF = 0x3f3f3f3f3f3f3f3f, MaxN = 2e5+5;
int n, m, q;
int dp[305][305];
pii question[MaxN];
int flag[305];

signed main() {
    memset(dp, 0x3f, sizeof(dp));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    for (int i = 1; i <= q; i++) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            flag[x] = 1;
            question[i] = {op, {x, 0}};
        }
        else {
            cin >> y;
            question[i] = {op, {x, y}};
        }
    }
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = a[i];
        if (flag[i]) continue;
        dp[u][v] = dp[v][u] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    vector<int> ans;
    while (q--) {
        auto [op, p] = question[q];
        auto [x, y] = p;
        if (op == 2) {
            if (dp[x][y] == INF) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(x);
        }
        else {
            auto [u, v, w] = a[x];
            dp[u][v] = min(dp[u][v], w);
            dp[v][u] = min(dp[v][u], w);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = min(dp[i][j], min(dp[i][u] + dp[u][v] + dp[v][j], dp[i][v] + dp[v][u] + dp[u][j]));
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto c : ans) cout << c << " ";
    return 0;
}