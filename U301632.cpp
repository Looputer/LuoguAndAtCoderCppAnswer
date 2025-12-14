//
// Created by 陆熠辰 on 25-10-19.
//
#include <iostream>
#define int long long
using namespace std;
int n;
double ans = 1e18;
int x[20], y[20], h[20];
int sq(int x) {
    return x * x;
}

double cal(int x1, int x2, int y1, int y2, int h1, int h2) {
    return sqrt(sq(x1 - x2) + sq(y1 - y2) + sq(h1 - h2));
}

int vis[20];
vector<int> v;
void dfs(int u, double dist) {
    if (dist > ans) return;
    if (u == n + 1) {
        ans = min(ans, dist);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) return;
        vis[i] = 1;
        int t1 = i, t2 = v.back();
        double tmp = 0;
        if (u != 1) {
            int t1 = i, t2 = v.back();
            tmp += cal(x[t1], x[t2], y[t1], y[t2], h[t1], h[t2]);
        }
        v.push_back(i);
        dfs(u+1, dist + tmp);
        vis[i] = 0; v.pop_back();
    }
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}