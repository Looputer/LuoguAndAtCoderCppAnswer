//
// Created by 陆熠辰 on 25-12-7.
//
#include <iostream>
#include <vector>
using namespace std;
const int MaxN = 2 * 1e5 + 5;
int n, x, y;
vector<int> v[MaxN];
vector<int> vis;
void dfs(int u, int fa) {
    if (u == y) {
        for (auto c : vis) {
            cout << c << ' ';
        }
        return;
    }
    for (int v : v[u]) {
        if (v != fa) {
            vis.push_back(v);
            dfs(v, u);
            vis.pop_back();
        }
    }
}

int main() {
    cin >> n >> x >> y;
    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vis.push_back(x);
    dfs(x, -1);
    return 0;
}