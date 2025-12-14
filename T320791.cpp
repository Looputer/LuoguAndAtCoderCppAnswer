//
// Created by 陆熠辰 on 25-11-28.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int MaxN = 500005;
struct node {
    int to;
    int w;
};
vector<node> v[MaxN];

int n, rt;
int depth[MaxN];
int ans;

int dfs(int u, int fa) {
    bool isLeaf = true;
    int mx = 0;

    vector<int> childF;

    for (auto &e : v[u]) {
        int v = e.to;
        int w = e.w;
        if (v == fa) continue;
        isLeaf = false;
        depth[v] = depth[u] + w;
        int fv = dfs(v, u);
        childF.push_back(fv);
        mx = max(mx, fv);
    }

    if (isLeaf) return depth[u];

    for (int fv : childF) {
        ans += (mx - fv);
    }

    return mx;
}

signed main() {
    cin >> n >> rt;
    for (int i = 1;i <= n - 1;i++) {
        int a, b;
        int t;
        cin >> a >> b >> t;
        v[a].push_back({b, t});
        v[b].push_back({a, t});
    }

    dfs(rt, 0);
    cout << ans << endl;
    return 0;
}