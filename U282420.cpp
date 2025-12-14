//
// Created by 陆熠辰 on 25-11-28.
//
#include <iostream>
#include <vector>
using namespace std;
const int MaxN = 1e6+5;
int n;
int dist[MaxN], sz[MaxN];
vector<int> v[MaxN];
void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto v : v[u]) {
        if (v != fa) {
            dist[v] = dist[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 2;i <= n;i++) {
        int x;
        cin >> x;
        v[x].push_back(i);
        v[i].push_back(x);
    }
    dfs(1, -1);
    for (int i = 1;i <= n;i++) {
        cout << sz[i] << " ";
    }
    return 0;
}