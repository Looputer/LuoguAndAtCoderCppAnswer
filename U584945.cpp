//
// Created by 陆熠辰 on 26-4-12.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int MaxN = 35;
int x, y, k, b, a[MaxN], dp[MaxN][25];

int dfs(int pos, int sum, bool lead, bool limit) {
    if (pos == 0) return sum == k;
    if (!lead && !limit && dp[pos][sum] != -1) return dp[pos][sum];
    int up = limit ? min(1ll, a[pos]) : 1;
    int res = 0;
    for (int i = 0; i <= up; i++) {
        res += dfs(pos - 1, sum + (i == 1), lead && i == 0, limit && i == a[pos]);
    }
    if (!lead && !limit) return dp[pos][sum] = res;
    return res;
}

int solve(int x) {
    int len = 0;
    while (x) {
        a[++len] = x % b;
        x /= b;
    }
    return dfs(len, 0, 1, 1);
}

signed main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y >> k >> b;
    cout << solve(y) - solve(x - 1) << endl;
}