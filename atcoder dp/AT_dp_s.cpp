//
// Created by 陆熠辰 on 26-4-12.
//
#include <iostream>
#include <cstring>
using namespace std;

const int MaxN = 1e5+5;
const int MOD = 1e9+7;
int a[MaxN], d, dp[MaxN][105];
string k;

int dfs(int pos, int sum, bool lead, bool limit) {
    if (pos == 0) return sum == 0 ? 1 : 0;
    if (!lead && !limit && dp[pos][sum] != -1) return dp[pos][sum];
    int up = limit ? a[pos] : 9;
    int res = 0;
    for (int i = 0; i <= up; i++) {
        res = (res + dfs(pos-1, (sum + i) % d, lead && !i, limit && i == a[pos])) % MOD;
    }
    if (!lead && !limit) return dp[pos][sum] = res % MOD;
    return res % MOD;
}

int solve(string& s) {
    int len = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        a[++len] = s[i] - '0';
    }
    return dfs(len, 0, true, true);
}

signed main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> d;
    cout << (solve(k) - 1 + MOD) % MOD;
}