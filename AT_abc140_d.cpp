//
// Created by 陆熠辰 on 2026/9/5.
//
#include <iostream>
#define int long long
using namespace std;

int n, k;
string s;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> s;
    int cnt = 0;
    s = " " + s;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i+1]) cnt++;
    }
    cout << min(n - 1, cnt + 2 * k);
}