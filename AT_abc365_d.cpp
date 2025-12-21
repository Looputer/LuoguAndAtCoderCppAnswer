//
// Created by 陆熠辰 on 25-12-21.
//
#include <iostream>
#include <string>
using namespace std;

const int MaxN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
string a;
int dp[MaxN][3];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> a;
    a = " " + a;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
        if (a[i] == 'R') dp[i][2] = -INF, dp[i][1] += 1;
        else if (a[i] == 'S') dp[i][1] = -INF, dp[i][0] += 1;
        else if (a[i] == 'P') dp[i][0] = -INF, dp[i][2] += 1;
    }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans << endl;
    return 0;
}