//
// Created by 陆熠辰 on 26-3-1.
//
#include <iostream>
#include <cstring>
using namespace std;
int n, m, a[505][505], vis[505][505];
bool flag;
void dfs(int x, int y, int mid) {
    if (x < 1 || x > n ||y < 1 || y > m) return;
    if (a[x][y] > mid || vis[x][y]) return;
    vis[x][y] = 1;
    if (x == n && y == m) {
        flag = true;
        return;
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (a[nx][ny] > mid) continue;
        dfs(nx, ny, mid);
    }
}

bool check(int mid) {
    memset(vis, 0, sizeof(vis));
    flag = false;
    dfs(1, 1, mid);
    return flag;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}