#include <iostream>
#include <cmath>
using namespace std;

const int MaxN = 100005;

int n;
int a[MaxN];
int dp[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);

    for (int i = 3; i <= n; i++) {
        int cost1 = dp[i-1] + abs(a[i] - a[i-1]);
        int cost2 = dp[i-2] + abs(a[i] - a[i-2]);
        dp[i] = min(cost1, cost2);
    }

    cout << dp[n] << endl;
    return 0;
}