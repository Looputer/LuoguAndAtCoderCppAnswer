//
// Created by 陆熠辰 on 2026/9/5.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, k, r, s, p;
string t;
bool used[MaxN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> r >> s >> p >> t;
    int ans = 0;
    t = " " + t;
    for (int i = 1; i <= n; i++) {
        if (i > k && used[i-k] && t[i] == t[i - k]) used[i] = false;
        else {
            used[i] = true;
            if (t[i] == 'r') ans += p;
            else if (t[i] == 's') ans += r;
            else ans += s;
        }
    }
    cout << ans << endl;
    return 0;
}