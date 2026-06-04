#include <iostream>
using namespace std;

const int N = 3005;

long long dp[N][N][2];

int n, mod;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> mod;

    dp[1][0][1] = 1;
    dp[1][1][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {

            dp[i + 1][j][1] =
                (dp[i + 1][j][1]
                + dp[i][j][1]
                + dp[i][j][0]) % mod;

            if (j + 1 <= n) {
                dp[i + 1][j + 1][1] =
                    (dp[i + 1][j + 1][1]
                    + 3 * dp[i][j][1]) % mod;

                dp[i + 1][j + 1][0] =
                    (dp[i + 1][j + 1][0]
                    + dp[i][j][0]) % mod;
            }

            if (j + 2 <= n) {
                dp[i + 1][j + 2][0] =
                    (dp[i + 1][j + 2][0]
                    + 2 * dp[i][j][1]) % mod;
            }
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        cout << dp[n][i][1];
        if (i != n - 1) cout << ' ';
    }

}