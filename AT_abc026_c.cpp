#include <iostream>
#include <vector>
#define int long long
using namespace std;

vector<int> edge[25];
int n;

int dfs(int u) {
    if (edge[u].empty()) return 1;
    
    int mx = 0, mn = 1e9;
    for (int v : edge[u]) {
        int t = dfs(v);
        mx = max(mx, t);
        mn = min(mn, t);
    }
    return mx + mn + 1;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        edge[x].push_back(i);
    }
    cout << dfs(1) << endl;
}