//
// Created by 陆熠辰 on 26-1-27.
//
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

struct node {
    int u, v, w;
};
const int MaxN = 1e5+5;
int n, m, q;
vector<node> vec;
int dp[505][MaxN], c[505], s[505];

void BellmanFord(int s) {
    memset(dp, 0x3f, sizeof(dp));
    dp[s][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int v = 1; v <= n; v++) dp[v][i] = dp[v][i-1];
        for (auto [u, v, w] : vec) {
            if (dp[u][i-1] < 1e17) {
                if (dp[v][i] > dp[u][i-1] + w) {
                    dp[v][i] = dp[u][i-1] + w;
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back({u, v, w});
        vec.push_back({v, u, w});
    }
    BellmanFord(1);
    cin >> q;
    while (q--) {
        int t;
        cin >> t;

        for (int i = 1; i < n; i++) {
            cin >> c[i];
            s[i] = s[i-1] + c[i];
        }

        if (t == 1) {
            cout << 0 << "\n";
            continue;
        }

        int minn = 2e18;
        bool found = false;
        for (int i = 1; i < n; i++) {
            if (dp[t][i] < 1e17) {
                minn = min(minn, dp[t][i] + s[i]);
                found = true;
            }
        }
        if (!found || minn > 1e17) cout << "-1\n";
        else cout << minn << "\n";
    }
    return 0;
}