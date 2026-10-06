#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int t, n, p[MaxN], sz[MaxN];

int pfind(int x) {
    if (x == p[x]) return x;
    return p[x] = pfind(p[x]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        int pu = pfind(u), pv = pfind(v);
        if (pu == pv) continue;
        sz[pv] += sz[pu];
        p[pu] = pv;
    }
    int ans = 2;
    for (int i = 1; i <= n; i++)
        if (pfind(i) == i && sz[i] & 1) ans = 3;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }

}

