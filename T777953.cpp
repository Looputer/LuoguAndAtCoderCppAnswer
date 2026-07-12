#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
int n, m, s[MaxN];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        s[l] += 1;
        s[r+1] -= 1;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        s[i] += s[i-1];
        ans = min(ans, s[i]);
    }
    cout << ans;
}