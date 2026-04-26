#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 2e6+5;
int n, dist[25][25], dp[25][1 << 20];

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> dist[i][j];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][1<<0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if ((i >> k & 1) == 0 && (i >> j & 1) == 1)
                    dp[k][i | (1 << k)] = min(dp[k][i | (1 << k)], dp[j][i] + dist[j][k]);
            }
        }
    }
    cout << dp[n-1][(1 << n) - 1];
}