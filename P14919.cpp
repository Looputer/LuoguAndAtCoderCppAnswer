//
// Created by 陆熠辰 on 26-3-8.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n;
vector<int> edge[MaxN];
int dp[MaxN], a[MaxN];

void dfs(int u, int fa) {
    int sum = 0;
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sum += dp[v];
    }
    if (edge[u].size() == 1 && u != 1) dp[u] = a[u];
    else dp[u] = min(a[u], sum);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        edge[x].push_back(i);
        edge[i].push_back(x);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0);
    cout << dp[1] << endl;
    return 0;
}