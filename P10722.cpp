//
// Created by 陆熠辰 on 25-12-10.
//
#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e5 + 5;

vector<int> v[MaxN];
int fa[MaxN], used[MaxN], changed[MaxN], n, q, op;
string s;

int dfs(int u) {
    if (changed[u] > 0) return changed[u];
    changed[u] = used[u] + dfs(fa[u]);
    return changed[u];
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> fa[i];
    cin >> s >> q;
    for (int i = 1; i <= q; i++) {
        cin >> op;
        used[op]++;
    }
    changed[1] = used[1] + 2;
    for (int i = 1; i <= n; i++) {
        if (!changed[i]) dfs(i);
    }
    for (int i = 0;i < n;i++) {
        bool x = s[i] - '0';
        if (changed[i+1] % 2 == 0) cout << x;
        else cout << !x;
    }
    return 0;
}