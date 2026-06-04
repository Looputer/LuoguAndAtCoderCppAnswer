#include <iostream>
#define int long long
using namespace std;

int n, s, a[105], b[105], dp[105][10005];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n ; i++) cin >> a[i] >> b[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n ;i++) {
        for (int j = 0 ; j <= s; j++) {
            if (j >= a[i] && dp[i-1][j-a[i]]) dp[i][j] = 1;
            if (j >= b[i] && dp[i-1][j-b[i]]) dp[i][j] = 2;
        }
    }
    if (!dp[n][s]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    string ans;
    int current = s;
    for (int i = n ; i >= 1; i--) {
        if (dp[i][current] == 1) {
            ans += 'H';
            current -= a[i];
        }
        else {
            ans += 'T';
            current -= b[i];
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}