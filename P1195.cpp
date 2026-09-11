//
// Created by 陆熠辰 on 2026/9/6.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
struct node {
    int u, v, w;
};
vector<node> edge;
int n, m, p[MaxN], k;

bool cmp(node a, node b) {
    return a.w < b.w;
}

int pfind(int x) {
    if (p[x] == x) return x;
    return p[x] = pfind(p[x]);
}

int kruskal() {
    int cnt = 0, sum = 0;
    for (auto [u, v, w] : edge) {
        int pu = pfind(u), pv = pfind(v);
        if (pu == pv) continue;
        cnt++;
        sum += w;
        p[pu] = pv;
        if (cnt < n - k) return -1;
    }
    if (n == k) return 0;
    return sum;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(edge.begin(), edge.end(), cmp);
    int sum = kruskal();
    if (sum == -1) cout << "No answer";
    else cout << sum;
}