#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, k, t, c, a[MaxN], delta, v[MaxN], ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> t >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        delta += v[i];
        int now = a[i] + delta;
        if (now < t) {
            delta += (t - now);
            v[i + k] -= (t - now);
            ans += c * (t - now);
        }
    }
    cout << ans;
}