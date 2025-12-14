//
// Created by 陆熠辰 on 25-10-19.
//
#include <iostream>
#define int long long

using namespace std;
int n, k, h, cnt;
vector<int> v;
void dfs(int u, int sum, int mul) {
    if (sum >= k || mul >= h) return;
    if (u == n + 1) {
        cnt++;
        return;
    }
    dfs(u + 1, sum + v[u], mul * v[u]);
    dfs(u+1, sum, mul);
}
signed main() {
    cin >> n >> k >> h;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dfs(1, 0, 1);
    cout << cnt << endl;
    return 0;
}