//
// Created by 陆熠辰 on 25-12-14.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MaxN = 2e6 + 5;
const int Mod = 1e5 + 3;
vector<int> vec[MaxN];
int dist[MaxN], cnt[MaxN];

void bfs(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    cnt[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto c : vec[u]) {
            if (dist[c] > dist[u] + 1) {
                dist[c] = dist[u] + 1;
                cnt[c] += cnt[u];
                q.push(c);
            }
            else if (dist[c] == dist[u] + 1) {
                cnt[c] += cnt[u];
            }
            cnt[c] %= Mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    bfs(1);
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}