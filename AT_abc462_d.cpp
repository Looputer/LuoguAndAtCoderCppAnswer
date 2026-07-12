#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
int n, d, s[MaxN];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        s[l] += 1;
        s[r - d + 1] -= 1;
    }
    int ans = 0;
    for (int i = 1; i <= MaxN - 5; i++) {
        s[i] += s[i-1];
        ans += s[i] * (s[i] - 1) / 2;
    }
    cout << ans;
}