//
// Created by 陆熠辰 on 25-12-14.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MaxN = 3e3+5;
const int INF = 0x3f3f3f3f;
int n, m;
vector<int> v[MaxN];
int dist[MaxN][MaxN];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(dist, 0x3f, sizeof(dist));
    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    for (int i = 1;i <= n;i++) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto j : v[u]) {
                if (dist[i][j] == INF) {
                    q.push(j);
                    dist[i][j] = dist[i][u] + 1;
                }
            }
        }
    }
    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
        cout << -1 << endl;
        return 0;
    }

    int ans = dist[s1][t1] + dist[s2][t2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int r1 = dist[s1][i] + dist[i][j] + dist[j][t1];
            int r2 = dist[s2][i] + dist[i][j] + dist[j][t2];
            int r = r1 + r2 - dist[i][j];
            if (r1 <= l1 && r2 <= l2) ans = min(ans, r);
            r1 = dist[t1][i] + dist[i][j] + dist[j][s1];
            r2 = dist[s2][i] + dist[i][j] + dist[j][t2];
            r = r1 + r2 - dist[i][j];
            if (r1 <= l1 && r2 <= l2) ans = min(ans, r);
        }
    }
    cout << ans - m << endl;
}