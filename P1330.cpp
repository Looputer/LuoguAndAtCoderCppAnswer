//
// Created by 陆熠辰 on 25-12-7.
//
#include <iostream>
#include <vector>
using namespace std;
const int MaxN = 1e5+5;
vector<int> v[MaxN];
int vis[MaxN];
int flag, n, m, cnt_shiro, cnt_kuro, ans;
void dfs(int u, int col) {
    if (vis[u]) return;
    vis[u] = col;
    if (col == 1) cnt_shiro++;
    else cnt_kuro++;
    for (auto c : v[u]) {
        if (vis[c] && vis[c] == col) {
            flag = 1;
        }
        dfs(c, 3 - col);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            cnt_shiro = 0;
            cnt_kuro = 0;
            dfs(i, 1);
            ans += min(cnt_shiro, cnt_kuro);
        }
    }
    if (flag) cout << "Impossible" << endl;
    else cout << ans << endl;
}