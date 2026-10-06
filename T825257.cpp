//
// Created by 陆熠辰 on 2026/10/6.
//
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 105;
int n, dp[MaxN][2005], maxn;

struct node {
    int t, d, p;
}thing[MaxN];

bool cmp(node a, node b) {
    return a.d < b.d;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> thing[i].t >> thing[i].d >> thing[i].p;
        maxn = max(maxn, thing[i].d);
    }
    int ans = 0;
    sort(thing + 1, thing + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxn; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - thing[i].t >= 0 && j <= thing[i].d - 1) dp[i][j] = max(dp[i][j], dp[i-1][j - thing[i].t] + thing[i].p);
        }
    }
    for (int i = 0; i < maxn; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}