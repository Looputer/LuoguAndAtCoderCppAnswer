//
// Created by 陆熠辰 on 26-1-2.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 3005;
string s, t;
int dp[MaxN][MaxN];
string ans;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    int lens = s.length(), lent = t.length();
    s = " " + s;
    t = " " + t;
    int x = lens, y = lent;
    for (int i = 1; i <= lens; i++) {
        for (int j = 1; j <= lent; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    while (x != 0 && y != 0) {
        if (s[x] == t[y]) {
            ans += s[x];
            x--;
            y--;
        }
        else {
            if (dp[x][y] == dp[x - 1][y]) x--;
            else if (dp[x][y] == dp[x][y - 1]) y--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}