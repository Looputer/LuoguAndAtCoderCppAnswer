#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int n, m;
int p[MaxN], sz[MaxN];

struct node {
    int a, b, t; 
} village[MaxN];

bool cmp(const node a, const node b) {
    return a.t < b.t;
}

int pfind(int x) {
    if (p[x] == x) return p[x];
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        village[i] = {x, y, t};
    }
    sort(village+1, village+m+1, cmp);
    for (int i = 1; i <= m; i++) {
        merge(village[i].a, village[i].b);
        if (sz[pfind(1)] == n) {
            cout << village[i].t;
            exit(0);
        }
    }
    cout << -1 << endl;
}