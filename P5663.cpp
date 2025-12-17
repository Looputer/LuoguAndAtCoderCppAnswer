#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 200000 + 5;
const int INF = 0x3f3f3f3f;

vector<int> g[MAXN];
int dist[MAXN];
int n, m, q;

void bfs(int s) {
    memset(dist, 0x3f, sizeof(dist));
    queue<int> que;
    dist[s] = 0;
    que.push(s);

    while (!que.empty()) {
        int u = que.front(); que.pop();
        for (int v : g[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    while (q--) {
        int a;
        long long L;
        cin >> a >> L;

        if (dist[a] == INF) {
            cout << "No\n";
        } else if (dist[a] <= L && ((L - dist[a]) % 2 == 0)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}