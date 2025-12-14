//
// Created by 陆熠辰 on 25-11-23.
//
#include <iostream>
#include <vector>
using namespace std;
int n;
const int MaxN = 1e5+5;
vector<int> v[MaxN];
int dist[MaxN], _size[MaxN];
void dfs(int u, int fa) {
    _size[u] = 1;
    for (auto c : v[u]) {
        if (c != fa) {
            dist[c] = dist[u] + 1;
            dfs(c, u);
            _size[u] += _size[c];
        }
    }
}
int main() {
    cin >> n;
    for (int i = 2;i <= n;i++) {
        int x;
        cin >> x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
    dfs(1, -1);
    for (int i = 1;i <= n;i++) {
        cout << dist[i] + 1<< endl;
    }
}