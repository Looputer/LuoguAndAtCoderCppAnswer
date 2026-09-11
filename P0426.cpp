//
// Created by 陆熠辰 on 2026/8/23.
//
#include <iostream>
#define int long long
using namespace std;

int n, m, k;
int a[1005][1005];
int end_x, end_y, start_x, start_y;
int ghost[1005][1005];

void dfs(int x, int y, int time) {
    if (x == end_x && y == end_y) {
        cout << time << endl;
        return;
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || nx >= n || ny <= 0 || ny >= m) continue;
        if (ghost[nx][ny]) {
            continue;
        }
        dfs(nx, ny, time+1);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> start_x >> start_y >> end_x >> end_y;
    for (int i = 1; i <= k; i++) {
        int kx, ky;
        cin >> kx >> ky;
        ghost[kx][ky] = 1;
    }
    dfs(start_x, start_y, 0);
}