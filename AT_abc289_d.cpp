#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, m, x, a[15], bad[MaxN], dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1;i <= m; i++) {
        int p;
        cin >> p;
        bad[p] = 1;
    }
    cin >> x;
    dp[0] = true;
    for (int i = 1; i <= x; i++) {
        if (bad[i]) continue;
        for (int j = 1; j <= n; j++) {
            if (i >= a[j] && dp[i-a[j]]) {
                dp[i] = 1;
                break;
            }
        }
    }
    if (dp[x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}