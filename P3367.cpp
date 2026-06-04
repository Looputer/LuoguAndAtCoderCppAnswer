#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, m;
int p[MaxN];

int pfind(int x) {
    if (p[x] == x) return p[x];
    else return p[x] = pfind(p[x]);
}

void merge(int x, int y) {
    int px = pfind(x);
    int py = pfind(y);
    if (px != py) {
        p[px] = py;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            merge(x, y);
        }
        else {
            int px = pfind(x);
            int py = pfind(y);
            if (px == py) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
}