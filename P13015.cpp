//
// Created by 陆熠辰 on 25-12-23.
//
#include <iostream>
using namespace std;

const int MaxN = 1e4+5;
int n;
int a[MaxN], dp[MaxN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i;j <= n; j++) {
            dp[j] = max(dp[j], dp[j - i] + a[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}