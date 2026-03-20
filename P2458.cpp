//
// Created by 陆熠辰 on 26-3-15.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int dp[MaxN][3], a[MaxN];
vector<int> vec[MaxN];
int n;

void dfs(int u, int fa) {
    dp[u][0] = a[u];
    dp[u][1] = 0x3f3f3f3f3f3f3f3f;
    int sum = 0;
    for (auto v : vec[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][2] += min(dp[v][1], dp[v][0]);
        dp[u][0] += min(dp[v][0], min(dp[v][1], dp[v][2]));
        sum += min(dp[v][0], dp[v][1]);
    }
    for (auto v : vec[u]) {
        if (v == fa) continue;
        dp[u][1] = min(dp[u][1], dp[v][0] + sum - min(dp[v][0], dp[v][1]));
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>  n;
    for (int i = 1; i <= n; i++) {
        int x,p, m;
        cin >> x >> p >> m;
        a[x] = p;
        for (int j = 1; j <= m; j++) {
            int r;
            cin >> r;
            vec[x].push_back(r);
            vec[r].push_back(x);
        }
    }
    dfs(1, -1);
    cout << min(dp[1][0], dp[1][1]) << "\n";
    return 0;
}