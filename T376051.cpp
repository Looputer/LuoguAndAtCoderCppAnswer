//
// Created by 陆熠辰 on 26-1-11.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e2+5;
const int INF = 0x3f3f3f3f;
int n, K;
int a[MaxN], dp[MaxN][MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 1; k * k >= i; k++) {
                int len = k * k;
                int l = i - len + 1;
                if (l < 1) break;
                int maxn = a[l];
                int minn = a[l];
                for (int p = l; p <= i; p++) {
                    maxn = max(maxn, a[p]);
                    minn = min(minn, a[p]);
                }
                if (dp[i - len][j - 1] != INF) dp[i][j] = max(dp[i][j], dp[i - len][j - 1] + (maxn - minn));
            }
        }
    }
    cout << dp[n][K] << endl;
    return 0;
}