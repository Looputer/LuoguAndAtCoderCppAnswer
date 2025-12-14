//
// Created by 陆熠辰 on 25-12-10.
//
#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 2 * 1e5 + 5;

vector<int> v[MaxN];
int vis[MaxN], even[MaxN], cnt, n;

void dfs(int u, int fa, int step) {
    if (vis[u]) return;
    vis[u] = 1;
    if (step % 2 == 0) {
        even[u] = 1;
        cnt++;
    }
    for (auto c : v[u]) {
        if (c == fa) continue;
        dfs(c, u, step + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1, 0);
    for (int i = 1; i <= n; i++) {
        if (even[i]) {
            cout << cnt << " ";
            continue;
        }
        cout << n - cnt << " ";
    }
    return 0;
}