//
// Created by 陆熠辰 on 26-2-1.
//
#include <iostream>
#include <cstring>
#include <vector>
#define int long long
#define pii pair<int, pair<int, int> >
using namespace std;

const int INF = 1e16, MaxN = 1e6+5;
struct node {
    int u, v, w;
}a[MaxN];
struct question {
    int op, x, y;
}questions[MaxN];
int n, m, q;
int dp[305][305];
int flag[MaxN];

void chmin(int &a, int b) {
    a = min(a, b);
}
signed main() {
    memset(dp, 0x3f, sizeof(dp));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            flag[x] = 1;
            questions[i] = {1, x, 0};
        }
        else {
            int x, y;
            cin >> x >> y;
            questions[i] = {2, x, y};
        }
    }
    for (int i = 1; i <= m; i++) {
        if (flag[i]) continue;
        auto [u, v, w] = a[i];
        dp[u][v] = dp[v][u] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    vector<int> ans;
    for (int i = q; i >= 1; i--) {
        auto [op, x, y] = questions[i];
        if (op == 2) {
            int res = dp[x][y];
            if (res >= INF / 2) res = -1;
            ans.push_back(res);
        }
        else {
            auto [u, v, w] = a[x];
            if (w < dp[u][v]) {
                dp[u][v] = min(dp[u][v], w);
                dp[v][u] = min(dp[v][u], w);
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= n; k++) {
                        dp[j][k] = min(dp[j][k], min(dp[j][u] + dp[u][v] + dp[v][k], dp[j][v] + dp[v][u] + dp[u][k]));
                    }
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto c : ans) cout << c << endl;
    return 0;
}