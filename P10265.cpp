//
// Created by 陆熠辰 on 2026/10/3.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

int n, m, a[1005][1005];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cnt1 += a[m][i];
        cnt2 += a[i][m];
    }
    cout << cnt1 << " " << cnt2 << endl;
}