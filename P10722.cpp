#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, q;
vector<int> edge[MaxN];
int col[MaxN], father[MaxN];
string s;
int cnt[MaxN];

void dfs(int u, int sum) {
    sum += cnt[u];
    if (sum % 2) col[u] ^= 1;
    for (auto v : edge[u]) {
        dfs(v, sum);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        edge[x].push_back(i+1);
        father[i+1] = x;
    }
    cin >> s;
    int idx = 1;
    for (auto ch : s) {
        int x = ch - '0';
        col[idx] = x;
        idx++;
    }
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        cnt[op]++;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << col[i];
    }

}