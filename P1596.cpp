//
// Created by 陆熠辰 on 25-10-12.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e2+5;
int n, m, cnt;
char a[MaxN][MaxN];
int vis[MaxN][MaxN];

void dfs(int x, int y) {
    if (vis[x][y] || a[x][y] != 'W') return;
    vis[x][y] = 1;
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {0, -1, 0, 1, 1, 1, 0, -1};
    for (int i = 0; i < 8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx > n || ty < 0 || ty > m) continue;
        if (vis[tx][ty]) continue;
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] + 1;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (a[i][j] == 'W' && vis[i][j] == 0) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}