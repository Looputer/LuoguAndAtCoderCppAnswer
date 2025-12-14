//
// Created by 陆熠辰 on 25-11-23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MaxN = 1e5+5;
int n;
vector<int> v[MaxN];
int sz[MaxN], dist[MaxN], cnt[MaxN];
void dfs(int u, int fa) {
    sz[u] = 1;
    for (int v : v[u]) {
        if (v != fa) {
            dist[v] = dist[u]+1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin >> n;
    for (int i = 2;i<=n;i++) {
        int x;
        cin >> x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
    dfs(1, -1);
    for (int i = 1;i<=n;i++) {
        cnt[dist[i]]++;
    }
    sort(cnt+1, cnt+n+1, cmp);
    cout << cnt[1] << endl;
    return 0;
}