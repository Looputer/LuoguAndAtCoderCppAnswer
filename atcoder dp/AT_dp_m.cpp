#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+10;
const int MOD = 1e9+7;
int dp[105][MaxN], s[MaxN];
int a[MaxN], n, k;

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        s[0] = 1;
        for (int j = 1; j <= k ;j++) {
            s[j] = s[j-1] + dp[i-1][j];
        }
        for (int j = 0; j <= k; j++) {
            if (j - a[i] >= 1) dp[i][j] += s[j] - s[j-a[i]-1];
            else dp[i][j] += s[j];
            dp[i][j] %= MOD;
        }
        
    }
    cout << dp[n][k];
    return 0;
}