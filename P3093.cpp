//
// Created by 陆熠辰 on 2026/8/9.
//
#include <iostream>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 1e4+5;

struct node {
    int d, g;
}a[MaxN];

int n;
priority_queue<int, vector<int>, greater<int>> q1;

bool cmp(node x, node y) {
    return x.d < y.d;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].g >> a[i].d;
    }
    sort(a+1, a+n+1, cmp);
    int ans = 0, time = 0;
    for (int i = 1; i <= n; i++) {
        int d = a[i].d, g = a[i].g;
        ans += g;
        time++;
        q1.push(g);
        if (d < time) {
            time --;
            ans -= q1.top();
            q1.pop();
        }
    }
    cout << ans << endl;
}