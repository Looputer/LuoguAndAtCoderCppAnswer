#include <iostream>
#define int long long
using namespace std;

int n, a[25], ans;
signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < (1 << n); i++) {
        double pos = 0.5;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int t = (i >> j) & 1;
            if (t == 0) t = 1;
            else t = -1;
            double nxpos = pos + a[j] * t;
            if (pos * nxpos < 0) cnt++;
            pos = nxpos;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}