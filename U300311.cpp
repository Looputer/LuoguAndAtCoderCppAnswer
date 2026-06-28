#include <iostream>
#define int long long
using namespace std;

int n, w, v;
int weight[25], value[25], c[25];
int ans;

void dfs(int pos, int sumW, int sumV, int sumC) {
    if (pos > n) {
        ans = max(ans, sumC);
        return;
    }
    dfs(pos+1, sumW, sumV, sumC);
    if (sumW + weight[pos] <= w && sumV + value[pos] <= v) {
        dfs(pos + 1, sumW + weight[pos], sumV + value[pos], sumC + c[pos]);
    } 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w >> v;
    for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i] >> c[i];
    dfs(1, 0, 0, 0);
    cout << ans << endl;
    return 0;
}