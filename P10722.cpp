#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e5+5;
vector<int> edge[MaxN];
int cnt[MaxN], col[MaxN], ans[MaxN], n;

void dfs(int u, int sum) {
    sum += cnt[u];
    int c = col[u];
    if (sum % 2) c ^= 1;
    ans[u] = c;
    for (auto v: edge[u]) {
        dfs(v, sum);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;
        edge[v].push_back(i+1);
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) col[i] = s[i-1] - '0';
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }

    return 0;
}