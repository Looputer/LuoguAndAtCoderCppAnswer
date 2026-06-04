#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, q, p[MaxN], sz[MaxN], flag[MaxN];

int pfind(int x) {
    if (x == p[x]) return p[x];
    else return p[x] = pfind(p[x]);
}

void merge(int x, int y) {
    int px = pfind(x);
    int py = pfind(y);
    if (px != py) {
        p[px] = py;
        sz[py] += sz[px];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 0;
    }
    while (q--) {
        int query;
        cin >> query;
        if (query == 1) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        else if (query == 2) {
            int v;
            cin >> v;
            if (flag[v] == 0) {
                sz[pfind(v)]++;
                flag[v] = 1;
            }
            else {
                sz[pfind(v)]--;
                flag[v] = 0;
            }
        }
        else {
            int v;
            cin >> v;
            if (sz[pfind(v)] >= 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}