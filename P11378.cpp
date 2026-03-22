//
// Created by 陆熠辰 on 25-12-7.
////
// Created by 陆熠辰 on 25-12-7.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxN = 1e5+5;

vector<int> v[MaxN];
int a[MaxN], dp[MaxN];
int n;


int dfs(int u) {
    if (dp[u] != 0) return dp[u];
    int res = 1;
    for (auto v : v[u]) {
        if (a[v] < a[u]) res += dfs(v);
    }
    return dp[u] = res;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 2;i <= n;i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int maxn = 0;
    for (int i = 1;i <= n;i++) {
        maxn = max(maxn, dfs(i));
    }
    cout << maxn << endl;
    return 0;
}