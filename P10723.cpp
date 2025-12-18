//
// Created by 陆熠辰 on 25-12-18.
//
#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e5 + 5;
vector<int> vec[MaxN];
int color[MaxN], vis[MaxN];
int n, ans;

bool dfs(int u, int fa) {
    bool f = 0;
    for (auto v : vec[u]) {
        if (v != fa && dfs(v, u)) f = 1;
    }
    if (!color[u] && f) ans++;
    return color[u] || f;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> color[i];
    for (int i = 2;i <= n;i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int k = -1;
    for (int i = 1;i <= n;i++) {
        if (color[i]) {
            k = i;
            break;
        }
    }
    dfs(k, 0);
    cout << ans << endl;
}