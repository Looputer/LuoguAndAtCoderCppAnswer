//
// Created by 陆熠辰 on 25-11-23.
//
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
int a[MaxN];
int sz[MaxN], dist[MaxN], cnt[MaxN], sum[MaxN];
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

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2;i<=n;i++) {
        int x;
        cin >> x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
    dist[1] = 1;
    dfs(1, -1);
    for (int i = 1;i<=n;i++) {
        cnt[dist[i]]++;
        sum[dist[i]] += a[i];
    }
    int maxi = 0;
    for (int i = 1;i<=n;i++) {
        maxi = max(maxi, sum[i]);
    }
    cout << maxi << endl;
    return 0;
}