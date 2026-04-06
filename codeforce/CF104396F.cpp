//
// Created by 陆熠辰 on 26-4-3.
//
#include <iomanip>
#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
double dp[60][60][60][60][5][5];
int A, B, C, D, X, Y;
double dfs(int a, int b, int c, int d, int x, int y) {
    double &val = dp[a][b][c][d][x][y];
    if (val >= 0) return val;
    int as = a + (x == 0) + (y == 0);
    int bs = b + (x == 1) + (y == 1);
    int cs = c + (x == 2) + (y == 2);
    int ds = d + (x == 3) + (y == 3);
    if (as >= A && bs >= B && cs >= C && ds >= D) return val = 0;
    int sum = a + b + c + d + (x != 4) + (y != 4);
    if (sum >= 54) return INF;
    val = 1;
    if (a < 13) val += (13.0 - a) / (54 - sum) * dfs(a + 1, b, c, d, x, y);
    if (b < 13) val += (13.0 - b) / (54 - sum) * dfs(a, b + 1, c, d, x, y);
    if (c < 13) val += (13.0 - c) / (54 - sum) * dfs(a, b, c + 1, d, x, y);
    if (d < 13) val += (13.0 - d) / (54 - sum) * dfs(a, b, c, d + 1, x, y);
    if (x == 4) {
        double mini = 1e18;
        for (int i = 0; i < 4; i++) mini = min(mini, dfs(a, b, c, d, i, y));
        mini *= 1.0 / (54 - sum);
        return mini;
    }
    if (y == 4) {
        double mini = 1e18;
        for (int i = 0; i < 4; i++) mini = min(mini, dfs(a, b, c, d, x, i));
        mini *= 1.0 / (54 - sum);
        return mini;
    }
    return val;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    double ans = dfs(0, 0, 0, 0, 4, 4);
    if (ans > 1e17) cout << -1 << endl;
    else cout << fixed << setprecision(10) << ans << endl;
}