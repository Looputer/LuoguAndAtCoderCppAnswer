//
// Created by 陆熠辰 on 25-11-16.
//
#include <iostream>
using namespace std;
int n, m;
char map[105][105], ans[105][105];
int a[105][105];
void dfs(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return;
    if (map[x][y] == '-') {
        ans[x][y] = map[x][y];
        return;
    }
    if (a[x][y]) return;
    a[x][y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (ans[x][y] == 'B') {
            ans[tx][ty] = 'W';
        }
        if (ans[x][y] == 'W') {
            ans[tx][ty] = 'B';
        }
        dfs(tx, ty);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> map[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1 || map[i][j] == '-') continue;
            map[i][j] = 'B';
            dfs(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '-') ans[i][j] = '-';
            cout << ans[i][j];
        }
        cout << endl;
    }
}