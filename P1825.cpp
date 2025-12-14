//
// Created by 陆熠辰 on 25-10-26.
//
#include <iostream>
using namespace std;

const int N = 305, INF = 0x3f3f3f3f;
int dis[N][N];
char mp[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy, tx, ty;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '@') {
                sx = i, sy = j;
            }
            if (mp[i][j] == '=') {
                tx = i, ty = j;
                mp[i][j] = '.';
            }
        }
    }

    queue<pair<int, int> > q;
    memset(dis, 0x3f, sizeof(dis));
    q.push({sx, sy});
    dis[sx][sy] = 0;

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        if ('A' <= mp[x][y] && mp[x][y] <= 'Z') {
            for (int i = 1;i <= n;i++) {
                for (int j = 1;j <= m;j++) {
                    if (i == x && i == y) continue;
                    if (mp[i][j] == mp[x][y]) {
                        if (dis[i][j] == INF) {
                            q.push({i, j});
                            dis[i][j] = dis[x][y];
                            mp[i][j] = '.';
                        }
                    }
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if (nx < 1 || nx > n || ny < 1 || ny > m) {
                    continue;
                }
                if (dis[nx][ny] == INF && (mp[nx][ny] == '.' || ('A' <= mp[nx][ny] && mp[nx][ny] <= 'Z'))) {
                    q.push({nx, ny});
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }
    }
    cout << dis[tx][ty];
}