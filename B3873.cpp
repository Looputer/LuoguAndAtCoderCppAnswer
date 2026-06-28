#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, L;
int c[MaxN], l[MaxN], dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> l[i];
    } 
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = L; j >= 1; j--) {
            int prev_j = max(0LL, j - l[i]);
            if (dp[prev_j] != INF) {
                dp[j] = min(dp[j], dp[prev_j] + c[i]);
            }
        }
    }
    if (dp[L] >= INF) cout << "no solution";
    else cout << dp[L];
}