//
// Created by 陆熠辰 on 25-10-26.
//
#include <iostream>
#include <queue>
using namespace std;

const int MaxN = 1005;
int n, m;
char s[MaxN][MaxN];
char ans[MaxN][MaxN];
int dist[MaxN][MaxN];

pair<int, int> pre[MaxN][MaxN];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    queue<pair<int, int> > q;

    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= m; j++) {
            ans[i][j] = s[i][j];
            dist[i][j] = -1;
            if (s[i][j] == 'E') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if (s[tx][ty] == '#') continue;
            if (dist[tx][ty] != -1) continue;
            dist[tx][ty] = dist[x][y] + 1;
            pre[tx][ty] = {x, y};
            q.push({tx, ty});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] != '.') continue;
            auto [x, y] = pre[i][j];
            if (x == i - 1 && y == j) ans[i][j] = '^';
            else if (x == i + 1 && y == j) ans[i][j] = 'v';
            else if (x == i && y == j - 1) ans[i][j] = '<';
            else if (x == i && y == j + 1) ans[i][j] = '>';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}