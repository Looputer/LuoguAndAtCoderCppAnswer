//
// Created by 陆熠辰 on 25-10-12.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e6 + 10;
bool vis[MaxN];
int ans, cnt, n, k, a[MaxN], p[MaxN], v[MaxN];

void dfs(int u) {
    if (u == n + 1) {
        bool flag1 = 1;
        bool flag2 = 1;
        for (int i = 2; i <= n; i += 2) {
            if (a[i] <= a[i - 1] || a[i] <= a[i + 1]) flag1 = 0;
        }
        for (int i = 1; i <= n; i += 2) {
            if (a[i] <= a[i - 1] || a[i] <= a[i + 1]) flag2 = 0;
        }
        if (!flag1 && !flag2) return;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = res * 10 + a[i];
        }
        p[++cnt] = res;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        a[i] = v[i];
        vis[i] = 1;
        dfs(u + 1);
        vis[i] = 0;
    }
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dfs(1);
    sort(p+1, p+1+cnt);
    for (int i = 1; i <= n; i++) {
        if (p[i] == p[i - 1]) continue;
        ans += p[i];
    }
    cout << ans << endl;
    return 0;
}
