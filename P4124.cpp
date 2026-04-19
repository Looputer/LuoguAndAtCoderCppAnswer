#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int l, r;
int a[11], dp[11];

int dfs(int pos, int last1, int last2, bool flag, bool f4, bool f8, bool lead, bool limit) {
    if (pos == 0) {
        if (f4 && f8) return 0;
        if (!flag) return 0;
        return 1;
    }
    int up = limit ? a[pos] : 9;
    int res = 0;
    for (int i = 0; i <= up; i++) {
        int nflag = 0;
        if (i == last1 && i == last2) nflag = 1;
        res += dfs(pos - 1, i, last1, nflag, f4 || i == 4, f8 || i == 8, lead && i == 0, limit && i == up);
    }
    return res;
}

int solve(int n) {
    int len = 0;
    while (n) {
        a[++len] = n % 10;
        n /= 10;
    }
    int ans = 0;
    for (int i = 1;i <= a[len]; i++) {
        ans += dfs(len - 1, i, -1, 0, i == 4, i == 8, 0, i == a[len]);
    }
    return ans;
}

signed main() {

}