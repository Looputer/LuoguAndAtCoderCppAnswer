//
// Created by 陆熠辰 on 2026/8/21.
//
#include <iostream>
#include <queue>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;

struct Chocolate {
    int a, b, c;
}chocolate[MaxN];

struct ChocolateCmp {
    bool operator () (const Chocolate& x, const Chocolate& y) const {
        return x.a > y.a;
    }
};

bool cmp(Chocolate& x, Chocolate& y) {
    return x.b > y.b;
}

int x, n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> n;
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> chocolate[i].a >> b >> chocolate[i].c;
        if (b > x) b = x;
        chocolate[i].b = b;
    }

    sort(chocolate + 1, chocolate + n + 1, cmp);
    priority_queue<Chocolate, deque<Chocolate>, ChocolateCmp> pq;

    int day = x;
    int p = 1;
    int cost = 0;

    while (day >= 1) {
        while (p <= n && chocolate[p].b >= day) {
            pq.push(chocolate[p]);
            p++;
        }
        if (pq.empty()) {
            cout << -1 << endl;
            return 0;
        }
        Chocolate top = pq.top();
        pq.pop();
        int limit = (p <= n) ? chocolate[p].b : 0;
        int useDay = day - limit;
        int use = min(top.c, useDay);
        cost += use * top.a;
        if (top.c > use) {
            top.c -= use;
            pq.push(top);
        }
        day -= use;
    }
    cout << cost << endl;
}