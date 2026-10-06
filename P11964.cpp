#include <iostream>
#include <vector>
using namespace std;

#define int long long

const int MaxN = 505;

int n, m, k;
vector<int> edge[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int s = 1; s <= n; s++) {
        bool last[MaxN] = {};
        bool now[MaxN] = {};

        last[s] = true;

        for (int step = 1; step <= k; step++) {
            for (int i = 1; i <= n; i++) {
                now[i] = false;
            }

            for (int u = 1; u <= n; u++) {
                if (!last[u])
                    continue;

                for (auto v : edge[u]) {
                    now[v] = true;
                }
            }

            int ans = 0;

            for (int i = 1; i <= n; i++) {
                if (now[i])
                    ans++;
            }

            cout << ans;

            if (step != k)
                cout << " ";

            for (int i = 1; i <= n; i++) {
                last[i] = now[i];
            }
        }

        cout << endl;
    }

    return 0;
}