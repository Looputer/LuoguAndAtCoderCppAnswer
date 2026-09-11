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
int n, p[MaxN];

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
    }
    return sum;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int w;
        cin >> w;
        edge.push_back({0, i, w});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            edge.push_back({i, j, w});
        }
    }
    for (int i = 0; i <= n; i++) p[i] = i;
    sort(edge.begin(), edge.end(), cmp);
    int sum = kruskal();
    cout << sum;
}