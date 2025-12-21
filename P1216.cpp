//
// Created by 陆熠辰 on 25-12-21.
//
#include <iostream>
using namespace std;

const int MaxN = 1005;
int n;
int a[MaxN][MaxN], dp[MaxN][MaxN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j < i) dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if (j != 1) dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
            dp[i][j] += a[i][j];
        }
    }
    int maxn = -1e9;
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, dp[n][i]);
    }
    cout << maxn << endl;
    return 0;
}