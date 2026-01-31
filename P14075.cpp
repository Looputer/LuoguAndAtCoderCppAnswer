#include <iostream>
#include <string>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n;
string s;
int a[MaxN], dp[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool vis[30];
    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        for (int j = i; j >= 1; j--) {
            if (vis[s[j] - 'a']) break;
            vis[s[j] - 'a'] = true;
            dp[i] = max(dp[i], dp[j - 1] + a[i - j + 1]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}