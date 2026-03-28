//
// Created by 陆熠辰 on 26-3-15.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

struct State {
    int h;
    bool full, comp;
};
const int MaxN = 1e5+5;
int l[MaxN], r[MaxN];
int ans, n;

State dfs(int u) {
    if (u == 0) return {0, 1, 1};
    auto L = dfs(l[u]);
    auto R = dfs(r[u]);
    int h = max(L.h, R.h) + 1;
    bool full = L.full && R.full && (L.h == R.h);
    bool comp = false;
    if (L.comp && R.comp) {
        if (L.h == R.h + 1 && R.full) comp = true;
        else if (L.h == R.h && L.full) comp = true;
    }
    if (comp) ans++;
    return {h, full, comp};
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    dfs(1);
    cout << ans;
}