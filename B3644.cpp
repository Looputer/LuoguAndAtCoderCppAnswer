//
// Created by 陆熠辰 on 25-12-28.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MaxN = 105;
vector<int> v[MaxN];
int n, deg[MaxN];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        while (cin >> a && a) {
            v[i].push_back(a);
            deg[a]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    vector<int> ans;
    while (q.size()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto v : v[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    for (auto v :ans) cout << v << " ";
    return 0;
}