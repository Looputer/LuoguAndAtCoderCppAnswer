#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int l, r;
int a[11], dp[12][11][11][2][2][2];

int dfs(int pos, int last1, int last2, bool flag, bool f4, bool f8, bool lead, bool limit) {
    if (pos == 0) {
        if (f4 && f8) return 0;
        if (!flag) return 0;
        return 1;
    }
    if (!limit && !lead && dp[pos][last1][last2][flag][f4][f8] != -1) return dp[pos][last1][last2][flag][f4][f8];
    int up = limit ? a[pos] : 9;
    int res = 0;
    for (int i = 0; i <= up; i++) {
        int nflag = 0;
        if (i == last1 && i == last2) nflag = 1;
        res += dfs(pos - 1, i, last1, flag || nflag, f4 || i == 4, f8 || i == 8, lead && i == 0, limit && i == up);
    }
    if (!limit && !lead) return dp[pos][last1][last2][flag][f4][f8] = res;
    return res;
}

int solve(int n) {
    if (n < 1e11) return 0;
    int len = 0;
    while (n) {
        a[++len] = n % 10;
        n /= 10;
    }
    int ans = 0;
    for (int i = 1;i <= a[len]; i++) {
        memset(dp, -1, sizeof(dp));
        ans += dfs(len - 1, i, 10, 0, i == 4, i == 8, 0, i == a[len]);
    }
    return ans;
}

signed main() {
    memset(dp, -1, sizeof(dp));
    cin >> l >> r;
    cout << solve(r) - solve(l - 1);
}

//wa