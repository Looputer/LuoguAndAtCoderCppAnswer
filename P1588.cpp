#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1005, INF = 0x3f3f3f3f;
int dis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int T;
    cin >> T;
    while (T--) {
        memset(dis, 0x3f, sizeof(dis));
        int x, y;
        cin >> x >> y;
        
        
        if (x >= N || y >= N) continue; 

        dis[x] = 0;
        queue<int> q; 
        q.push(x);
        
        bool found = false;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            
            if (t == y) {
                cout << dis[y] << "\n";
                found = true;
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
        
        if (!found) {
            cout << -1 << "\n"; 
        }
    }
    return 0;
}