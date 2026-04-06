//
// Created by 陆熠辰 on 26-3-29.
//
#include <iostream>
#include <iomanip>
#define int long long
using namespace std;

const int MaxN = 305;
double dp[MaxN][MaxN][MaxN];
int n, vis[MaxN][MaxN][MaxN];

double dfs(int x, int y, int z) {
    if (x == 0 && y == 0 && z == 0) return 0;
    if (vis[x][y][z]) return dp[x][y][z];
    dp[x][y][z] = 0;
    vis[x][y][z] = 1;
    if (x >= 1) dp[x][y][z] += 1.0 * x / n * dfs(x-1, y, z);
    if (y >= 1) dp[x][y][z] += 1.0 * y / n * dfs(x+1, y-1, z);
    if (z >= 1) dp[x][y][z] += 1.0 * z / n * dfs(x, y+1, z-1);
    dp[x][y][z] += 1;
    dp[x][y][z] /= 1.0 * (x + y + z) / n;
    return dp[x][y][z];
}

signed main() {
    cin >> n;
    int s1 = 0, s2 = 0, s3 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 1) s1++;
        else if (x == 2) s2++;
        else if (x == 3) s3++;
    }
    dfs(s1, s2, s3);
    cout << fixed << setprecision(10) << dp[s1][s2][s3] << endl;
}
