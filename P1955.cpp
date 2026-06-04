#include <iostream>
#include <map>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, t, p[MaxN], sz[MaxN];

int pfind(int x) {
    if (p[x] == x) return p[x];
    else return p[x] = pfind(p[x]);
}   

void merge(int x, int y)
{
    int px = pfind(x);
    int py = pfind(y);
    if (px != py) {
        p[px] = py;
        sz[py] += sz[px];
    }
}
int a[MaxN], b[MaxN], c[MaxN];

void solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        mp[a[i]] = 0;
        mp[b[i]] = 0;
    }
    int idx = 1;
    for (int i = 1; i <= 2 * n; i++) p[i] = i;
    for (auto t : mp) {
        int x = t.first;
        mp[x] = idx;
        idx++;
    }
    for (int i = 1; i <= n; i++) {
        int x = a[i], y = b[i], z = c[i];
        x = mp[x], y = mp[y];
        if (z == 1) merge(x, y);
    }
    for (int i = 1; i <= n; i++) {
        int x = a[i], y = b[i], z = c[i];
        x = mp[x], y = mp[y];
        if (z == 0) {
            int px = pfind(x);
            int py = pfind(y);
            if (px == py) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

signed main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}