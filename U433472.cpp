//
// Created by 陆熠辰 on 25-12-7.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2 * 1e5 + 5;
vector<int> v[MaxN];
int vis1[MaxN], vis2[MaxN];
int n, m, a, b, cnt1, cnt2;

void dfs(int u, int visit[], int ed) {
    if (visit[u]) return;
    visit[u] = 1;
    for (auto c : v[u]) {
        if (c == ed) continue;
        dfs(c, visit, ed);
    }
}

signed main() {
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(a, vis1, b);
    dfs(b, vis2, a);
    for (int i = 1; i <= n; i++) {
        if (vis1[i] && !vis2[i]) cnt1++;
        if (vis2[i] && !vis1[i]) cnt2++;
    }
    cout << cnt1 * cnt2 << endl;
    return 0;
}