#include <iostream>
#include <string>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
string s;
int dp[205][205];

signed main() {
    cin >> s;
    int n = s.length();
    s = " " + s;
    for (int len = 2; len <= n; len++) {
        for (int L = 1; L <= n; L++) {
            int R = L + len - 1;
            if (R > n) break;
            int flag = 0;
            if ((s[L] == '(' && s[R] == ')') || (s[L] == '[' && s[R] == ']')) flag = 1;
            if (flag) dp[L][R] = dp[L+1][R-1] + 2;
            for (int k = L; k < R; k++) {
                dp[L][R] = max(dp[L][R], dp[L][k] + dp[k+1][R]);
            }
        }
    }
    cout << dp[1][n] << endl;
}