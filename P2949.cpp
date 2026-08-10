//
// Created by 陆熠辰 on 2026/8/9.
//
#include <iostream>
#include <queue>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;

struct node {
    int d, p;
}a[MaxN];

int n;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int> > q2;

bool cmp(node x, node y) {
    return x.d < y.d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].d >> a[i].p;
    }
    sort(a+1, a+n+1, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int d = a[i].d, p = a[i].p;
        ans += p;
        q2.push(p);
        if (q2.size() > d) {
            ans -= q2.top();
            q2.pop();
        }
    }
    cout << ans << endl;
}