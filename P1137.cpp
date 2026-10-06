//
// Created by 陆熠辰 on 2026/10/4.
//
#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
int n, m;
vector<int> edge[MaxN];
int dp[MaxN], indeg[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        indeg[u]--;
        for (auto v : edge[u]) {
            dp[v] = max(dp[u] + 1, dp[v]);
            if (indeg[v] == 0) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << endl;
    }
    return 0;
}