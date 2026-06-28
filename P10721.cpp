#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, m, a[MaxN], dp[MaxN];
string s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n; i++) cin >> a[i];
    cin >> m >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m / 3; j++) {
            dp[j] = max(dp[j], dp[j-i] + a[i]);
        }
    }
    int ans = 0, i = 0;
    while (i <= m - 3) {
        if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
            int cnt = 0;
            while (i <= m - 3 && s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
                cnt++;
                i += 3;
            }
            ans += dp[cnt];
        } else {
            i++;
        }
    }
    cout << ans;
}