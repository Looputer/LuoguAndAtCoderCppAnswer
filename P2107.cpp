//
// Created by 陆熠辰 on 2026/8/9.
//
#include <iostream>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 1e5+5;

struct node {
    int x, t;
}a[MaxN];

int n, m;
priority_queue<int> pq;

bool cmp(node n1, node n2) {
    return n1.x < n2.x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].t;
    }
    sort(a+1, a+1+n, cmp);
    int ans = 0, time = 0, maxi = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i].x, t = a[i].t;
        ans++;
        time += t + x - a[i-1].x;
        pq.push(t);
        while (time > m && pq.size()) {
            time -= pq.top();
            pq.pop();
            ans--;
        }
        maxi = max(maxi, ans);
    }
    cout << maxi << endl;
}