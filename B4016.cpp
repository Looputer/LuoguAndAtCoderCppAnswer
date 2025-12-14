//
// Created by 陆熠辰 on 25-12-7.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MaxN = 1e5+5;
vector<int> v[MaxN];
int dist[MaxN];
int n;

void dfs(int u, int fa) {
    for (auto c : v[u]) {
        if (c != fa) {
            dist[c] = dist[u] + 1;
            dfs(c, u);
        }
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
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    dist[0] = 0;
    dfs(1, 0);
    int p = 1, maxi = -1e9;
    for (int i = 1;i <= n;i++) {
        if (dist[i] > maxi) {
            p = i;
            maxi = dist[i];
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[p] = 0;
    dist[0] = 0;
    dfs(p, 0);
    maxi = -1e9;
    for (int i = 1;i <= n;i++) {
        if (dist[i] > maxi) {
            maxi = dist[i];
        }
    }
    cout << maxi << endl;
    return 0;
}