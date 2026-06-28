#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MaxN = 2e6+5;
int n, a, b, c;
int dp[MaxN];
int dfs(int u) {
    if (u <= c) return 1;
    if (dp[u] != -1) return dp[u];
    return dp[u] = (dfs(u-a) + dfs(u-b)) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    cout << dfs(n) % MOD << endl;
}