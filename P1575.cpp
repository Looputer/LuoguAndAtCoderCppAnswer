//
// Created by 陆熠辰 on 26-1-25.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

typedef pair<int, int> pii;
int m, n;
vector<pii> vec[105];
int dp[1005][1005], w[1005], v[1005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> w[i] >> v[i] >> x;
        vec[x].push_back(pii(w[i], v[i]));
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= m; j++) dp[i][j] = dp[i - 1][j];
        for (int j = 0; j <= m; j++) {
            for (pii k : vec[i]) {
                int we = k.first, vi = k.second;
                if (j - we >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - we] + vi);
                }
            }
        }
    }
    cout << dp[100][m] << '\n';
    return 0;
}