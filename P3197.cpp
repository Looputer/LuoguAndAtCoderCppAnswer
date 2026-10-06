//
// Created by 陆熠辰 on 2026/9/13.
//
#include <iostream>
#define int long long
using namespace std;

const int MOD = 100003;
int m, n;

int qsm(int a, int b, int p) {
    int ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    int ans = (qsm(m, n, MOD) - m * qsm(m-1, n-1, MOD) % MOD + MOD) % MOD;
    cout << ans << endl;
}