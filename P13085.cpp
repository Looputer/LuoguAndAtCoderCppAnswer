//
// Created by 陆熠辰 on 26-4-12.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int l, r, a[20], dp[20][10];
int dfs(int pos, int last, bool lead, bool limit) {
    if (pos == 0) return 1;
    if (!lead && !limit && dp[pos][last] != -1) return dp[pos][last];
    int up = limit ? a[pos] : 9;
    int sum = 0;
    for (int i = 0; i <= up; i++) {
        if (abs(i-last) < 2) continue;
        if (lead && !i) sum += dfs(pos-1, -10, lead && !i, limit && i == a[pos]);
        else sum += dfs(pos-1, i, lead && !i, limit && i == a[pos]);
    }
    if (!lead && !limit) dp[pos][last] = sum;
    return sum;
}

int solve(int x) {
    int len = 0;
    while (x) {
        a[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, -10, true, true);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;
}