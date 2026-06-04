#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
const int INF = 1e9;
int n, s, c[MaxN], l[MaxN], sum, dp[MaxN], ans = INF;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> l[i];
        l[i] = min(l[i], s);
        sum += l[i];

    }
    if (sum < s) {
        cout << "no solution";
        exit(0);
    }
    memset(dp, 0x3f, sizeof(dp));
}
