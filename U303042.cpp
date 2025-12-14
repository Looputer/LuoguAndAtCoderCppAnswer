//
// Created by 陆熠辰 on 25-10-19.
//
#include <iostream>
#define int long long
using namespace std;
int n, m, cnt;
char map[105][105];
int a[105][105], p[10000005];
void dfs(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return;
    if (a[x][y] || map[x][y] != 'W') return;
    a[x][y] = cnt;
    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> map[i] + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '*' && a[i][j] == 0) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans = max(ans, p[i]);
    }
    cout << cnt << endl;
    return 0;
}


