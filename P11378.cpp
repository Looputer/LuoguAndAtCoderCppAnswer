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

bool cmp(int a, int b) {
    return a > b;
}

void dfs(int u, int fa) {
    if (dp[u]) return;
    dp[u] = 1;
    for (auto c : v[u]) {
        if (c == fa) continue;
        if (a[c] < a[u]) dfs(c, u);
        dp[u] += dp[c];
    }
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
    for (int i = 1;i <= n;i++) {
        if (dp[i]) continue;
        dfs(i, -1);
    }
    sort(dp+1, dp+n+1, cmp);
    cout << dp[1] << endl;
}