//https://luogu.com.cn/problem/U300333
#include <iostream>
#define int long long
using namespace std;

int n, m, k;
vector<int> v;
int a[15], vis[15];
int ans;
void dfs(int u) {
    if (u == n + 1) {
        string tmp = "";
        for (int i = 0; i < m; i++) {
            tmp += to_string(a[v[i]]);
        }
        if (tmp.size() >= 10 || tmp.size() == 0) return;
        int x = stoi(tmp);
        if (x <= k) ans = max(ans, x);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) continue;
        vis[i] = 1; v.push_back(i);
        dfs(u + 1);
        vis[i] = 0; v.pop_back();
    }
}

signed main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}