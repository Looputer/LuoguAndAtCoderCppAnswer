#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int INF = 1e18;
struct Toy {
    int p, s;
    bool operator < (const Toy& other) const {
        if (s != other.s) return s < other.s;
        return p < other.p;
    }
};
int n, m;
Toy toys[5005];
int dp[2][5005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> toys[i].p >> toys[i].s;
    }
    sort(toys + 1, toys + m + 1);
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int current = i % 2;
        int prev = (i - 1) % 2;
        for (int j = 0; j < n; j++) {
            dp[current][j] = INF;
        }
        for (int j = i; j <= n; j++) {
            dp[current][j] = dp[current][j-1];
            if (dp[prev][j-1] != INF) {
                int cost = dp[prev][j-1] + toys[i].s * abs(toys[i].p - j);
                dp[current][j] = min(dp[current][j], cost);
            }
        }
    }
    cout << dp[m % 2][n] << endl;
    return 0;
}