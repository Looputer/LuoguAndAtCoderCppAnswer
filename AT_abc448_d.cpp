//
// Created by 陆熠辰 on 26-3-8.
//
#include <iostream>
#include <map>
#include <vector>
#define int long long
using namespace std;


const int MaxN = 2e5+5;
map<int, int> mp;
int cnt;
int has_num[MaxN];
vector<int> edge[MaxN];
int a[MaxN];
int n;
void dfs(int u, int fa) {
    mp[a[u]]++;
    if (mp[a[u]] == 2) cnt++;
    if (cnt >= 1) has_num[u] = 1;
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
    mp[a[u]]--;
    if (mp[a[u]] == 1) cnt--;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (has_num[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}