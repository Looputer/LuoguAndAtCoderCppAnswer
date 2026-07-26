//
// Created by 陆熠辰 on 2026/7/25.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, k, a[MaxN], cnt[MaxN];
int calc(int x) {
    if (x == 0) return 0;
    memset(cnt, 0, sizeof(cnt));
    int dis = 0, ans = 0;
    int R = 1;
    for (int L = 1; L <= n; L++) {
        while (R <= n && (dis < x || cnt[a[R]] > 0)) {
            if (cnt[a[R]] == 0) dis++;
            cnt[a[R]]++;
            R++;
        }
        ans += R - L;
        cnt[a[L]]--;
        if (cnt[a[L]] == 0) dis--;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << calc(k) - calc(k-1);
}