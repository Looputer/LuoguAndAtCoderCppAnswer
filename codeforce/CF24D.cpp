#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int MaxN = 1005;
double dp[MaxN][MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    for (int i = n - 1; i >= 1; i--) {

        vector<double> a(m+1), b(m+1), c(m+1), d(m+1);

        for (int j = 1; j <= m; j++) {
            if (j == 1) {
                b[j] = 2;
                c[j] = -1;
                d[j] = 3 + dp[i+1][j];
            }
            else if (j == m) {
                a[j] = -1;
                b[j] = 2;
                d[j] = 3 + dp[i+1][j];
            }
            else {
                a[j] = -1;
                b[j] = 3;
                c[j] = -1;
                d[j] = 4 + dp[i+1][j];
            }
        }
        for (int j = 2; j <= m; j++) {
            double k = a[j] / b[j-1];
            b[j] -= k * c[j-1];
            d[j] -= k * d[j-1];
        }

        dp[i][m] = d[m] / b[m];
        for (int j = m-1; j >= 1; j--) {
            dp[i][j] = (d[j] - c[j] * dp[i][j+1]) / b[j];
        }
    }

    cout << fixed << setprecision(10) << dp[x][y] << "\n";
}