#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, m, p[MaxN], sz[MaxN], flag[MaxN];
vector<int> edge[MaxN];

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
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    vector<int> closed;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        closed.push_back(x);
    }
    reverse(closed.begin(), closed.end());
    int cnt = 0;
    vector<string> ans;
    for (auto point : closed) {
        cnt ++;
        flag[point] = 1;
        for (auto c : edge[point]) {
            if (flag[c] == 1) {
                merge(c, point);
            }
        }
        if (sz[pfind(point)] == cnt) ans.push_back("YES");
        else ans.push_back("NO"); 
         
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << endl;
    }

}