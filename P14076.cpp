//
// Created by 陆熠辰 on 25-12-11.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;
typedef pair<int, int> pii;

const int MaxN = 1e5+5;
vector<pii> v[MaxN];
int sum, maxn, n;

void dfs(int u, int fa, int dis) {
    maxn = max(maxn, dis);
    for (auto c : v[u]) {
        if (c.first == fa) continue;
        dfs(c.first, u, dis + c.second);
    }
}

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
        sum += w;
    }
    dfs(1, -1, 0);
    cout << sum * 2 - maxn;
    return 0;
}