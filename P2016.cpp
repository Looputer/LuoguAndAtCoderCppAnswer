//
// Created by 陆熠辰 on 26-3-15.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1505;
int n;
vector<int> edge[MaxN];
int dp[MaxN][2];
void dfs(int u, int fa) {
    dp[u][1] = 1;
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k, c;
        cin >> k >> c;
        for (int j = 1; j <= c; j++) {
            int r;
            cin >> r;
            edge[k].push_back(r);
            edge[r].push_back(k);
        }

    }
    //cout << "www" << endl;
    dfs(0, -1);
    cout << min(dp[0][0], dp[0][1]) << '\n';
    return 0;
}