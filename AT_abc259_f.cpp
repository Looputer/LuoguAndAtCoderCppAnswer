//
// Created by 陆熠辰 on 26-4-11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

typedef pair<int, int> pii;
const int MaxN = 3e5+5;
const int INF = 1e18;
int n, d[MaxN], dp[MaxN][2];
vector<pii> edge[MaxN];

void dfs(int u, int fa) {
    int sum = 0;
    vector<int> diffs;
    for (auto [v, w] : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sum += dp[v][1];
        int diff = dp[v][0] + w - dp[v][1];
        if (diff > 0) diffs.push_back(diff);
    }
    sort(diffs.begin(), diffs.end(), greater<int>());
    dp[u][0] = sum;
    if (d[u] == 0) dp[u][0] = -INF;
    else {
        for (int i = 0; i < min((int)diffs.size(), d[u] - 1); i++) {
            dp[u][0] += diffs[i];
        }
    }
    dp[u][1] = sum;
    for (int i = 0; i < min((int)diffs.size(), d[u]); i++) {
        dp[u][1] += diffs[i];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << dp[1][1] << endl;
}