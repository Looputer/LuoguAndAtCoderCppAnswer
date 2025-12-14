//https://luogu.com.cn/problem/U300331
#include <iostream>
#define int long long
using namespace std;
int n, x;
vector<int> v;
int vis[15];
int ans = -1e18;
int c[15], d[15];
void dfs(int u) {
    if (u == n + 1) {
        int tmp = x;
        for (int i = 0;i < v.size(); i++) {
            int t = v[i];
            tmp = tmp * c[t];
            tmp = tmp - d[t];
            ans = max(ans, tmp);
        }
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
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    ans = x;
    dfs(1);
    cout << ans << endl;
    return 0;
}