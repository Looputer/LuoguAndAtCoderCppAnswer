#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e6 + 5;
vector<int> vec[MaxN];
int n, m;
int school[MaxN], cnt1, cnt2;

void dfs(int n, int g) {
    school[n] = g;
    if (g == 1) cnt1++;
    else cnt2++;
    for (auto v : vec[n]) {
        if (!school[v]) dfs(v, 3 - g);
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int down = 0, up = 0;
    for (int i = 1; i <= n; i++) {
        cnt1 = cnt2 = 0;
        if (!school[i]) dfs(i, 1);
        down += min(cnt1, cnt2);
        up += max(cnt1, cnt2);
    }
    cout << down << " " << up;
    return 0;
}