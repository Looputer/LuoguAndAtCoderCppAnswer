#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e3+5;
int n, p[MaxN], dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) 
            dp[i] = max(dp[i], dp[j-1] + p[i-j+1]);
    cout << dp[n] << endl;
}