//
// Created by 陆熠辰 on 2026/8/23.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, m;
int p[MaxN], sz[MaxN], ans[MaxN];
vector<int> edge[MaxN];

int pfind(int x) {
    if (x == p[x]) return x;
    return p[x] = pfind(p[x]);
}

bool merge(int x, int y) {
    int px = pfind(x);
    int py = pfind(y);
    if (px == py) return false;
    if (sz[px] < sz[py]) swap(px, py);
    p[py] = px;
    sz[px] += sz[py];
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        cnt++;
        for (auto j : edge[i]) {
            if (j >= i) {
                if (merge(i, j)) cnt--;
            }
        }
        ans[i] = cnt;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}