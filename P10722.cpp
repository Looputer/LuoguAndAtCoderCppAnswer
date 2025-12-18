//
// Created by 陆熠辰 on 25-12-10.
//
#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e5 + 5;
string s, ans;
vector<int> vec[MaxN];
int n, q;
int vis[MaxN];

void dfs(int u, int fa, int col) {
    col ^= vis[u];
    if (col) {
        if (s[u] == '1') s[u] = '0';
        else s[u] = '1';
    }
    for (auto v : vec[u]) {
        if (v != fa) dfs(v, u, col);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        vec[a].push_back(i);
    }
    cin >> s;
    s = " " + s;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        vis[x] ^= 1;
    }
    dfs(1, -1, 0);
    ans = s.substr(1, n);
    cout << ans << '\n';
    return 0;
}