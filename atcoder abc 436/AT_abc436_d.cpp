//
// Created by 陆熠辰 on 25-12-15.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<string> map;
vector<pii> warp[26];
int ans = -1;
queue<pii> q;
vector<bool> used(26, false);

int main() {
    cin >> n >> m;
    map.resize(n);
    for (int i = 0;i < n;i++) {
        cin >> map[i];
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if ('a' <= map[i][j] && map[i][j] <= 'z') {
                warp[map[i][j] - 'a'].push_back({i, j});
            }
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[0][0] = 0;
    q.push({0, 0});
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
        if ('a' <= map[x][y] && map[x][y] <= 'z') {
            int c = map[x][y] - 'a';
            if (!used[c]) {
                used[c] = true;
                for (auto [nx, ny] : warp[c]) {
                    if (dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << dist[n-1][m-1] << "\n";
    return 0;
}