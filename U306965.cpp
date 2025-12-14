//
// Created by 陆熠辰 on 25-10-19.
//
#include <iostream>
#define int long long
using namespace std;

int n, m;
int a[105][105];
int dp[105][105];
int dfs(int x, int y) {
    int ans = 0;
    if (dp[x][y] != 0) return dp[x][y];
    if (a[x-1][y] < a[x][y] && x - 1 >= 1) ans = max(ans, dfs(x - 1, y));
    if (a[x+1][y] < a[x][y] && x + 1 <= n) ans = max(ans, dfs(x + 1, y));
    if (a[x][y-1] < a[x][y] && y - 1 >= 1) ans = max(ans, dfs(x, y - 1));
    if (a[x][y+1] < a[x][y] && y + 1 <= m) ans = max(ans, dfs(x, y + 1));

    dp[x][y] = ans + 1;
    return ans + 1;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}