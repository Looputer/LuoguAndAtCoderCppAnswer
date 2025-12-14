//
// Created by 陆熠辰 on 25-11-16.
//
#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int MaxN = 1e3+5;
const int Max = 1e5+5;
int n, m, idx;
int map[MaxN][MaxN], a[MaxN][MaxN], c[Max];
int cnt;
void dfs(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return;
    if (a[x][y]) return;
    cnt++;
    a[x][y] = idx;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (map[tx][ty] == map[x][y]) continue;
        dfs(tx, ty);
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1lld", &map[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            idx++;
            dfs(i, j);
            c[a[i][j]]++;
        }
    }
    for (int i = 1;i <= m;i++) {
        int x, y;
        cin >> x >> y;
        cout << c[a[x][y]] << endl;
    }
    return 0;
}