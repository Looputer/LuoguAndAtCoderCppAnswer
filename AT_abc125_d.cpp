//
// Created by 陆熠辰 on 2026/9/5.
//
#include <iostream>
#define int long long
using namespace std;

int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0, minn = 1e18, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < 0) cnt++;
        sum += abs(x);
        minn = min(minn, abs(x));
    }
    if (cnt % 2 == 0) cout << sum << endl;
    else cout << sum - 2 * minn << endl;
}