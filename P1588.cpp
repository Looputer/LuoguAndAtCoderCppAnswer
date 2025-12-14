//
// Created by 陆熠辰 on 25-10-26.
//

#include <iostream>
using namespace std;

const int N = 1005, INF = 0x3f3f3f3f;
int dis[N];
char mp[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(dis, 0x3f, sizeof(dis));
        int x, y;
        cin >> x >> y;
        dis[x] = 0;
        queue<int> q;
        q.push(x);
        while (q.size()) {
            int t = q.front();
            q.pop();
            if (t == y) {
                cout << dis[y] << endl;
                break;
            }

            if (t + 1 < N && dis[t+1] == INF) {
                q.push(t+1);
                dis[t+1] = dis[t] + 1;
            }

            if (t - 1 >= 1 && dis[t-1] == INF) {
                q.push(t-1);
                dis[t-1] = dis[t] + 1;
            }

            if (2 * t < N && dis[t * 2] == INF) {
                q.push(t*2);
                dis[t*2] = dis[t] + 1;
            }
        }

        cout << dis[y] << endl;
    }
}