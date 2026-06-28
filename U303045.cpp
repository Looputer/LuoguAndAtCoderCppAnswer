#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, m, d;
char mp[505][505];
bool vis[505][505];

struct Point {
    int x, y;
};

void bfs(int sx, int sy) {
    queue<Point> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        int x = curr.x;
        int y = curr.y;

        for (int dx = -d; dx <= d; ++dx) {
            int dy_abs = d - abs(dx);
            int dy_choices[] = {dy_abs, -dy_abs};
            
            for (int dy : dy_choices) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (mp[nx][ny] == '*' && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
                
                if (dy_abs == 0) break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m >> d)) return 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == '*' && !vis[i][j]) {
                ans++;
                bfs(i, j);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}