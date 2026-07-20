#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, k, a[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    int R = 0;
    for (int L = 1; L <= n; L++) {
        while (R < n && sum <= k) {
            R++;
            sum += a[R];
        }
        if (sum > k) cout << R << " ";
        else cout << -1 << " ";
        sum -= a[L];
    }
}