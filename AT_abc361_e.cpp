//
// Created by 陆熠辰 on 25-12-7.
//
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

typedef pair<int,int> pii;
const int MaxN = 2 * 1e5 + 5;

vector<pii> v[MaxN];
int dist[MaxN];
int n, sum, maxi, p;

void dfs(int u, int fa) {
    for (auto [j, w] : v[u]) {
        if (j == fa) continue;
        dist[j] = dist[u] + w;
        dfs(j, u);
    }
}

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        sum += c;
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxi) {
            p = i;
            maxi = dist[i];
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[p] = 0;
    dfs(p, -1);
    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxi) {
            maxi = dist[i];
        }
    }
    int ans = sum * 2 - maxi;
    cout << ans << endl;
    return 0;
}