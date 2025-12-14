//
// Created by 陆熠辰 on 25-10-26.
//
#include <iostream>
using namespace std;

const int N = 1005, INF = 0x3f3f3f3f;
int dis[N][N];
char mp[N][N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    queue<pair<int, int> > q;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'H') {
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    }



    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (dis[nx][ny] == INF && mp[nx][ny] != '#') {
                q.push({nx, ny});
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dis[i][j] <= k) {
                cnt++;
            }
        }
    }

    cout << cnt;
}