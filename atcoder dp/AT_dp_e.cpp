//
// Created by 陆熠辰 on 25-12-28.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
const int INF = 1e10+5;

int dp[MaxN];
int weight[105], value[105];
int n, w, tol;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
        tol += value[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = tol; j >= value[i]; j--) {
            if (dp[j - value[i]] + weight[i] < dp[j]) {
                dp[j] = dp[j - value[i]] + weight[i];
            }
        }
    }
    int ans = 0;
    for (int i = tol; i >= 1; i--) {
        if (dp[i] <= w) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}