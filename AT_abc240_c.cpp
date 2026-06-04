#include <iostream>
using namespace std;

const int MaxN = 105;
const int MaxX = 1e4 + 5;

int n, X;
int a[MaxN], b[MaxN];
bool dp[MaxN][MaxX];

int main() {

    cin >> n >> X;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j <= X; j++) {

            if (!dp[i - 1][j]) continue;

            if (j + a[i] <= X) {
                dp[i][j + a[i]] = true;
            }

            if (j + b[i] <= X) {
                dp[i][j + b[i]] = true;
            }
        }
    }

    cout << (dp[n][X] ? "Yes" : "No") << endl;
}