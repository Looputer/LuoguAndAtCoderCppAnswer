//
// Created by 陆熠辰 on 2026/8/2.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 5e4+5;

struct node {
    int w, s;
}cow[MaxN];

bool cmp(node a, node b) {
    return (a.w + a.s) < (b.w + b.s);
}
int n;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i].w >> cow[i].s;
    }
    sort(cow + 1, cow + n + 1, cmp);
    int sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int now = sum - cow[i].s;
        ans = min(ans, now);
        sum += cow[i].w;
    }
    cout << ans << endl;
}