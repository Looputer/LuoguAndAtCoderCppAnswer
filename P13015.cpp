//
// Created by 陆熠辰 on 25-12-23.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e4+5;
int n;
int a[MaxN], dp[MaxN];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i;j >= 1; j--) {
            dp[i] = max(dp[i], dp[j-1] + a[i-j+1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << dp[n] << endl;
    return 0;
}