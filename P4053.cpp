//
// Created by 陆熠辰 on 2026/8/9.
//
#include <iostream>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 1e5 + 50005;

struct node {
    int t1, t2;
}a[MaxN];

int n;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;

bool cmp(node x, node y) {
    return x.t2 < y.t2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t1 >> a[i].t2;
    }
    sort(a+1, a+n+1, cmp);
    int ans = 0, time = 0;
    for (int i = 1; i <= n; i++) {
        int t1 = a[i].t1, t2 = a[i].t2;
        ans++;
        time += t1;
        q1.push(t1);
        if (time > t2) {
            time -= q1.top();
            ans--;
            q1.pop();
        }
    }
    cout << ans << endl;
}