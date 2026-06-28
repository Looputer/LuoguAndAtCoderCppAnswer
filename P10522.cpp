#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n;
vector<int> edge[MaxN];

void dfs(int u) {
    if (u) cout << u << " ";
    for (int i = edge[u].size() - 1; i >= 0; i--) {
        dfs(edge[u][i]);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        edge[x].push_back(i);
    }
    dfs(0);
    return 0;
}