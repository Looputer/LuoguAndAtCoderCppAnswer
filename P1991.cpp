//
// Created by 陆熠辰 on 2026/9/6.
//
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#define int long long
using namespace std;

typedef pair<int,int> pii;
const int MaxN = 505;
pii pos[MaxN];
int s, n, x[MaxN];

struct node {
    int u, v;
    double w;
};

double sq(double x) {
    return x * x;
}

double dist(pii a, pii b) {
    return sqrt(sq(a.first - b.first) + sq(a.second - b.second));
}

int pfind(int u) {
    if (u == x[u]) return u;
    return x[u] = pfind(x[u]);
}

vector<node> edge;

double kruskal() {
    int cnt = 0;
    double sum = 0;
    for (auto [u, v, w] : edge) {
        int pu = pfind(u), pv = pfind(v);
        if (pu == pv) continue;
        cnt++;
        sum = w;
        x[pu] = pv;
        if (cnt == n - s) break;
    }
    return sum;
}

bool cmp(node a, node b) {
    return a.w < b.w;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> n;
    for (int i = 1; i <= n; i++) cin >> pos[i].first >> pos[i].second;
    for (int i = 1; i <= n; i++) x[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            double dis = dist(pos[i], pos[j]);
            // cout << dis << endl;
            edge.push_back({i, j, dis});
        }
    }
    sort(edge.begin(), edge.end(), cmp);
    cout << fixed << setprecision(2) << kruskal() << endl;
}