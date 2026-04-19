//
// Created by 陆熠辰 on 26-4-12.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int MaxN = 35;
int l, r, s[MaxN], dp[MaxN][25];

int dfs(int pos, int last, bool lead, bool limit) {
    if (pos == 0) return 1;
    if (!lead && !limit && dp[pos][last] != -1) return dp[pos][last];
    int up = limit ? s[pos] : 9;
    int res = 0;
    for (int i = 0; i <= up; i++) {
        if (i >= last)
            res += dfs(pos - 1, i, lead && !i, limit && i == s[pos]);
    }
    if (!limit && !last) return dp[pos][last] = res;
    return res;
}

int solve(int x) {
    int len = 0;
    while (x) {
        s[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, 0, 1, 1);
}

signed main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> l >> r) cout << solve(r) - solve(l- 1) << endl;

}