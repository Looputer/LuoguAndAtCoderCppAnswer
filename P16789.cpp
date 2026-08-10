//
// Created by 陆熠辰 on 2026/8/9.
//
#include <iostream>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 2e5+5;

struct node {
    int t, w, key;
}a[MaxN];

int n;
priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int, vector<int>, greater<int>> q2;

bool cmp(node x, node y) {
    return x.t < y.t;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].w >> a[i].key;
    }
    sort(a+1, a+1+n, cmp);
    int cnt = 0, time = 0, sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int t = a[i].t, w = a[i].w, key = a[i].key;
        cnt += key, time++, sum += w;
        if (key) q1.push(w);
        else q2.push(w);
        if (time > t) {
            if (key) {
                if (q2.size()) {
                    sum -= q2.top();
                    q2.pop();
                } else {
                    sum -= q1.top();
                    q1.pop();
                    cnt--;
                }
            } else {
                sum -= q2.top();
                q2.pop();
            }
            time--;
        }

    }
    cout << cnt << " " << sum << endl;
}