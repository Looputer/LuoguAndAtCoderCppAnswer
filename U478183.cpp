#include <iostream>
#include <queue>
#define int long long
using namespace std;

int n, m, k;
const int MaxN = 2e3+5;
int mp[MaxN][MaxN];

int cal(int x, int y) {
    int cnt = 0;
    if (mp[x-1][y] == 1) cnt++;
    if (mp[x+1][y] == 1) cnt++;
    if (mp[x][y-1] == 1) cnt++;
    if (mp[x][y+1] == 1) cnt++;
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }
    queue<pair<int,int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 0 && cal(i, j) >= 2) { 
                q.push({i, j});
                mp[i][j] = 1;
            }
        }
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
            if (mp[nx][ny] == 0 && cal(nx, ny) >= 2) { 
                q.push({nx, ny});
                mp[nx][ny] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j]) ans++;
        }
    }
    cout << ans;
}