
#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

const int MAXN = 2005;
const long long INF = 4e18;

int H, W;
int R[MAXN], C[MAXN];
char A[MAXN][MAXN];

long long dp[MAXN][MAXN][2][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;

    for (int i = 1; i <= H; i++) cin >> R[i];
    for (int j = 1; j <= W; j++) cin >> C[j];

    for (int i = 1; i <= H; i++) {
        cin >> (A[i] + 1);
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            for (int r = 0; r < 2; r++) {
                for (int c = 0; c < 2; c++) {
                    dp[i][j][r][c] = INF;
                }
            }
        }
    }

    dp[1][1][0][0] = 0;
    dp[1][1][1][0] = R[1];
    dp[1][1][0][1] = C[1];
    dp[1][1][1][1] = R[1] + C[1];

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {

            for (int r = 0; r < 2; r++) {
                for (int c = 0; c < 2; c++) {

                    long long cur = dp[i][j][r][c];
                    if (cur == INF) continue;

                    // 向下
                    if (i < H) {
                        int nr = r ^ ((A[i][j] - '0') ^ (A[i + 1][j] - '0'));

                        dp[i + 1][j][nr][c] =
                            min(dp[i + 1][j][nr][c],
                                cur + (nr ? R[i + 1] : 0));
                    }

                    // 向右
                    if (j < W) {
                        int nc = c ^ ((A[i][j] - '0') ^ (A[i][j + 1] - '0'));

                        dp[i][j + 1][r][nc] =
                            min(dp[i][j + 1][r][nc],
                                cur + (nc ? C[j + 1] : 0));
                    }
                }
            }
        }
    }

    long long ans = INF;

    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) {
            ans = min(ans, dp[H][W][r][c]);
        }
    }

    cout << ans << '\n';
    return 0;
}