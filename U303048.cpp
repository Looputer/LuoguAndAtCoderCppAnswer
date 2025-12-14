//
// Created by 陆熠辰 on 25-11-22.
//
#include <iostream>
#include <cstring>
using namespace std;

int n, m;
char a[105][105];
int vis[105][105];
int ans, flag;

bool check(int i, int j) {
    if (vis[i][j] == 1) return true;
    return false;
}

void dfs(int x, int y) {
    if (check(x, y)) return;
    vis[x][y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 1 || tx > n || ty < 1 || ty > m) {
            flag = 1;
            continue;
        }
        if (a[tx][ty] == '.' && !check(tx, ty)) {
            dfs(tx, ty);
        }
    }
}

int main() {
    cin >> n >> m;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] + 1;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'K') {
                x = i;
                y = j;
                a[i][j] = '.';
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') {
                a[i][j] = '.';
                flag = 0;
                memset(vis, 0, sizeof(vis));
                dfs(x, y);
                if (flag) ans++;
                a[i][j] = '#';
            }
        }
    }
    cout << ans << endl;
    return 0;
}