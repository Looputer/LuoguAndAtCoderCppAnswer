//
// Created by 陆熠辰 on 26-2-27.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
vector<int> edge[MaxN];
vector<int> ans;
int removed[MaxN], deg[MaxN];
int n, cnt;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (removed[u]) continue;
        int center = -1;
        for (auto v : edge[u]) {
            if (!removed[v]) {
                center = v;
                break;
            }
        }
        if (center == -1) continue;
        ans.push_back(edge[center].size());
        cnt += edge[center].size() + 1;
        removed[center] = 1;
        for (auto v : edge[center]) {
            removed[v] = 1;
            for (auto x : edge[v]) {
                if (!removed[x]) {
                    deg[x]--;
                    if (deg[x] == 1) q.push(x);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
    return 0;
}